/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QRDetector.cpp
 * Author: Ilya Petrikov
 * 
 * Created on February 28, 2020, 1:09 PM
 */

#include <map>

#include "QRDetector.h"

QRDetector::QRDetector() {
    captureVideo();
}

QRDetector::~QRDetector() {
}

void QRDetector::resetCalculatedValues() {
    marker = 0;
    diagonalValue = 0;
    medianValueFirst = 0;
    medianValueSecond = 0;
    distance = 0;
    slope = 0;
    aligner = 0;
    orientation = 0;
}

void QRDetector::captureVideo() {
    cv::VideoCapture captureVid(-1);
    if (!captureVid.isOpened()) {
        std::cout << "Can't capture video by path: " + capturePath << std::endl;
    } else {
        captureVid >> originalImage;
        mark = cv::Mat(originalImage.size(), CV_8UC3);
        while (true) {
            initializeQrValues();
            resetCalculatedValues();
            captureVid >> originalImage;
            testImage = originalImage.clone();
            if (!originalImage.empty()) {
                findAllContours();
                std::vector<cv::Moments> contoursMoments(contours.size());
                std::vector<cv::Point2f> contoursMassCenter(contours.size());
                for (unsigned int elem = 0; elem < contours.size(); elem++) {
                    contoursMoments[elem] = cv::moments(contours[elem], false);
                    contoursMassCenter[elem] = cv::Point2f(
                            contoursMoments[elem].m10 / contoursMoments[elem].m00,
                            contoursMoments[elem].m01 / contoursMoments[elem].m00);
                }
                approximateContours(contoursMassCenter);
                cv::waitKey(10);
            } else {
                std::cout << "Image is empty!" << std::endl;
            }
        }
    }
}

void QRDetector::initializeQrValues() {
    mark = cv::Scalar(0, 0, 0);
    qrRawValue = cv::Mat::zeros(100, 100, CV_8UC3);
    qrValue = cv::Mat::zeros(100, 100, CV_8UC3);
    qrGray = cv::Mat::zeros(100, 100, CV_8UC1);
    qrThreshold = cv::Mat::zeros(100, 100, CV_8UC1);
}

void QRDetector::findAllContours() {
    cv::cvtColor(originalImage, grayImage, CV_RGB2GRAY);
    cv::GaussianBlur(originalImage, originalImage, cv::Size(5, 5), 0);
    cv::Canny(grayImage, edgesImage, 100, 200, 3);
    cv::findContours(edgesImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    for (unsigned int i = 0; i < contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
    }
    //    cv::imshow("Contours", drawing);
}

float QRDetector::EuclideanDistance(cv::Point2f pnt1, cv::Point2f pnt2) {
    return sqrt(pow(abs(pnt1.x - pnt2.x), 2) + pow(abs(pnt1.y - pnt2.y), 2));
}

float QRDetector::calculatePerpendicularPointsDistance(cv::Point2f medianFirst, cv::Point2f medianSecond, cv::Point2f diagonal) {
    float vX = -((medianSecond.y - medianFirst.y) / (medianSecond.x - medianFirst.x));
    float vY = 1.0f;
    float vZ = (((medianSecond.y - medianFirst.y) / (medianSecond.x - medianFirst.x)) * medianFirst.x) - medianFirst.y;
    float distance = (vX * diagonal.x + (vY * diagonal.y) + vZ) / sqrt((vX * vX) + (vY * vY));
    return distance;
}

float QRDetector::longestSideSlope(cv::Point2f point1, cv::Point2f point2, int& aligner) {
    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;
    if (dy != 0) {
        aligner = 1;
        return (dy / dx);
    } else {
        aligner = 0;
        return 0.0;
    }
}

void QRDetector::slopeIdentification(std::map<std::string, float> distanceMap, std::vector<cv::Point2f> contoursMassCenter) {
    if (distanceMap.at("AB") > distanceMap.at("BC") && distanceMap.at("AB") > distanceMap.at("CA")) {
        diagonalValue = C;
        medianValueFirst = A;
        medianValueSecond = B;
    } else if (distanceMap.at("CA") > distanceMap.at("AB") && distanceMap.at("CA") > distanceMap.at("BC")) {
        diagonalValue = B;
        medianValueFirst = A;
        medianValueSecond = C;
    } else if (distanceMap.at("BC") > distanceMap.at("AB") && distanceMap.at("BC") > distanceMap.at("CA")) {
        diagonalValue = A;
        medianValueFirst = B;
        medianValueSecond = C;
    }

    // Draw slope(diagonal) line
    cv::line(testImage, contoursMassCenter[medianValueFirst], contoursMassCenter[medianValueSecond], cv::Scalar(0, 255, 0), 1, 16);
    // Draw distance(perpendicular) line
    cv::line(testImage,
            contoursMassCenter[diagonalValue],
            cv::Point2f((contoursMassCenter[medianValueFirst].x + contoursMassCenter[medianValueSecond].x) / 2,
            (contoursMassCenter[medianValueFirst].y + contoursMassCenter[medianValueSecond].y) / 2),
            cv::Scalar(255, 0, 0), 1, 16
            );
}

void QRDetector::drawApproximatedContours() {
    cv::Mat approxDraw = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    if (approximatedContours.size() > 0) {
        for (unsigned int i = 0; i < approximatedContours.size(); i++) {
            cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            cv::drawContours(approxDraw, approximatedContours, i, color, 2, 8, hierarchy, 0, cv::Point());
        }
        //cv::imshow("Approximated Contours", approxDraw);
        approximatedContours.clear();
    }
}

void QRDetector::approximateContours(std::vector<cv::Point2f> contoursMassCenter) {
    if (contours.size() != 0) {
        for (unsigned int i = 0; i < contours.size(); i++) {
            cv::approxPolyDP(contours[i], pointsSequence, cv::arcLength(contours[i], true) * 0.02, true);
            if (pointsSequence.size() == 4) {
                approximatedContours.push_back(pointsSequence);
                int currentIndex = i;
                int vCounter = 0;
                while (hierarchy[currentIndex][2] != -1) {
                    currentIndex = hierarchy[currentIndex][2];
                    vCounter++;
                }
                if (hierarchy[currentIndex][2] != -1) {
                    vCounter++;
                }
                if (vCounter >= 5) {
                    switch (marker) {
                        case 0: A = i;
                            break;
                        case 1: B = i;
                            break;
                        case 2: C = i;
                            break;
                    }
                    marker++;
                }
            }
        }
        drawApproximatedContours();
        if (marker >= 3) {
            std::map<std::string, float> distanceMap;
            std::string namesList[] = {"AB", "BC", "CA"};
            std::vector<std::pair<int, int> > contourPair{
                {A, B},
                {B, C},
                {C, A}};
            cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            for (unsigned int i = 0; i < contourPair.size(); i++) {
                cv::line(testImage, contoursMassCenter[contourPair[i].first], contoursMassCenter[contourPair[i].second], color, 2);
                cv::putText(testImage, namesList[i],
                        cv::Point2f(
                        (contoursMassCenter[contourPair[i].first].x + contoursMassCenter[contourPair[i].second].x) / 2,
                        (contoursMassCenter[contourPair[i].first].y + contoursMassCenter[contourPair[i].second].y) / 2),
                        cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255, 255));
                distanceMap.insert(std::make_pair(namesList[i], EuclideanDistance(contoursMassCenter[contourPair[i].first], contoursMassCenter[contourPair[i].second])));
            }
            slopeIdentification(distanceMap, contoursMassCenter);
        }

        if (diagonalValue != 0 && medianValueFirst != 0 && medianValueSecond != 0) {
            topValue = diagonalValue;
            distance = calculatePerpendicularPointsDistance(contoursMassCenter[medianValueFirst], contoursMassCenter[medianValueSecond], contoursMassCenter[diagonalValue]);
            slope = longestSideSlope(contoursMassCenter[medianValueFirst], contoursMassCenter[medianValueSecond], aligner);
            if (distance != 0 && slope != 0) {
                if (aligner == 0) {
                    bottomValue = medianValueFirst;
                    rightValue = medianValueSecond;
                } else if (slope < 0 && distance < 0) {
                    bottomValue = medianValueFirst;
                    rightValue = medianValueSecond;
                    orientation = 0;
                } else if (slope > 0 && distance < 0) {
                    rightValue = medianValueFirst;
                    bottomValue = medianValueSecond;
                    orientation = 1;
                } else if (slope < 0 && distance > 0) {
                    rightValue = medianValueFirst;
                    bottomValue = medianValueSecond;
                    orientation = 2;
                } else if (slope > 0 && distance > 0) {
                    bottomValue = medianValueFirst;
                    rightValue = medianValueSecond;
                    orientation = 3;
                }
                cv::putText(testImage, "Bottom", contoursMassCenter[bottomValue], cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255, 255));
                cv::putText(testImage, "Right", contoursMassCenter[rightValue], cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255, 255));
                cv::putText(testImage, "Top", contoursMassCenter[topValue], cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255, 255));
            }

            if (topValue < contours.size() && rightValue < contours.size() && bottomValue < contours.size()
                    && cv::contourArea(contours[topValue]) > 10
                    && cv::contourArea(contours[rightValue]) > 10
                    && cv::contourArea(contours[bottomValue]) > 10
                    ) {

                std::vector<cv::Point2f> leftTop, rightTop, leftDown;
                std::vector<cv::Point2f> tempLeftTop, tempRightTop, tempLeftDown;
                cv::Point2f searchingValue;
                std::vector<cv::Point2f> source, destination;
                cv::Mat warpingImage;
                
                
                
                std::vector<cv::Point2f> L, M, O, tempL, tempM, tempO;
                cv::Point2f N;
                std::vector<cv::Point2f> src, dst;
                cv::Mat warp_matrix;
                getMarksVerticies(contours, topValue, slope, tempL);
                getMarksVerticies(contours, rightValue, slope, tempM);
                getMarksVerticies(contours, bottomValue, slope, tempO);
                updateCornerOr(orientation, tempL, L);
                updateCornerOr(orientation, tempM, M);
                updateCornerOr(orientation, tempO, O);

                src.push_back(L[0]);
                src.push_back(M[1]);
                src.push_back(N);
                src.push_back(O[3]);

                dst.push_back(cv::Point2f(0, 0));
                dst.push_back(cv::Point2f(qrValue.cols, 0));
                dst.push_back(cv::Point2f(qrValue.cols, qrValue.rows));
                dst.push_back(cv::Point2f(0, qrValue.rows));

                if (src.size() == 4 && dst.size() == 4) // Failsafe for WarpMatrix Calculation to have only 4 Points with src and dst
                {
                    warp_matrix = getPerspectiveTransform(src, dst);
                    warpPerspective(originalImage, qrRawValue, warp_matrix, cv::Size(qrValue.cols, qrValue.rows));
                    cv::copyMakeBorder(qrRawValue, qrValue, 10, 10, 10, 10, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
                    cv::cvtColor(qrValue, qrGray, CV_RGB2GRAY);
                    cv::threshold(qrGray, qrThreshold, 127, 255, CV_THRESH_BINARY);
                }
                //Draw contours on the image
                cv::drawContours(originalImage, contours, topValue, cv::Scalar(255, 200, 0), 2, 8, hierarchy, 0);
                cv::drawContours(originalImage, contours, rightValue, cv::Scalar(0, 0, 255), 2, 8, hierarchy, 0);
                cv::drawContours(originalImage, contours, bottomValue, cv::Scalar(255, 0, 100), 2, 8, hierarchy, 0);
            }
        }

    }
    imshow("Image", testImage);
    cv::imshow("QR code", qrThreshold);
}

void QRDetector::getMarksVerticies(std::vector<std::vector<cv::Point> > contours, int c_id, float slope, std::vector<cv::Point2f>& quad) {
    cv::Rect box;
    box = cv::boundingRect(contours[c_id]);
    cv::Point2f M0, M1, M2, M3;
    cv::Point2f A, B, C, D, W, X, Y, Z;
    A = box.tl();
    B.x = box.br().x;
    B.y = box.tl().y;
    C = box.br();
    D.x = box.tl().x;
    D.y = box.br().y;
    W.x = (A.x + B.x) / 2;
    W.y = A.y;
    X.x = B.x;
    X.y = (B.y + C.y) / 2;
    Y.x = (C.x + D.x) / 2;
    Y.y = C.y;
    Z.x = D.x;
    Z.y = (D.y + A.y) / 2;

    float dmax[4];
    dmax[0] = 0.0;
    dmax[1] = 0.0;
    dmax[2] = 0.0;
    dmax[3] = 0.0;

    float pd1 = 0.0;
    float pd2 = 0.0;

    if (slope > 5 || slope < -5) {

        for (unsigned int i = 0; i < contours[c_id].size(); i++) {
            pd1 = calculatePerpendicularPointsDistance(C, A, contours[c_id][i]); // Position of point w.r.t the diagonal AC 
            pd2 = calculatePerpendicularPointsDistance(B, D, contours[c_id][i]); // Position of point w.r.t the diagonal BD

            if ((pd1 >= 0.0) && (pd2 > 0.0)) {
                updateCorner(contours[c_id][i], W, dmax[1], M1);
            } else if ((pd1 > 0.0) && (pd2 <= 0.0)) {
                updateCorner(contours[c_id][i], X, dmax[2], M2);
            } else if ((pd1 <= 0.0) && (pd2 < 0.0)) {
                updateCorner(contours[c_id][i], Y, dmax[3], M3);
            } else if ((pd1 < 0.0) && (pd2 >= 0.0)) {
                updateCorner(contours[c_id][i], Z, dmax[0], M0);
            } else
                continue;
        }
    } else {
        int halfx = (A.x + B.x) / 2;
        int halfy = (A.y + D.y) / 2;

        for (unsigned int i = 0; i < contours[c_id].size(); i++) {
            if ((contours[c_id][i].x < halfx) && (contours[c_id][i].y <= halfy)) {
                updateCorner(contours[c_id][i], C, dmax[2], M0);
            } else if ((contours[c_id][i].x >= halfx) && (contours[c_id][i].y < halfy)) {
                updateCorner(contours[c_id][i], D, dmax[3], M1);
            } else if ((contours[c_id][i].x > halfx) && (contours[c_id][i].y >= halfy)) {
                updateCorner(contours[c_id][i], A, dmax[0], M2);
            } else if ((contours[c_id][i].x <= halfx) && (contours[c_id][i].y > halfy)) {
                updateCorner(contours[c_id][i], B, dmax[1], M3);
            }
        }
    }

    quad.push_back(M0);
    quad.push_back(M1);
    quad.push_back(M2);
    quad.push_back(M3);

}

void QRDetector::updateCorner(cv::Point2f P, cv::Point2f ref, float& baseline, cv::Point2f& corner) {
    float temp_dist;
    temp_dist = EuclideanDistance(P, ref);

    if (temp_dist > baseline) {
        baseline = temp_dist; // The farthest distance is the new baseline
        corner = P; // P is now the farthest point
    }

}

void QRDetector::updateCornerOr(int orientation, std::vector<cv::Point2f> IN, std::vector<cv::Point2f> &OUT) {
    cv::Point2f M0, M1, M2, M3;
    if (orientation == 0) {
        M0 = IN[0];
        M1 = IN[1];
        M2 = IN[2];
        M3 = IN[3];
    } else if (orientation == 1) {
        M0 = IN[1];
        M1 = IN[2];
        M2 = IN[3];
        M3 = IN[0];
    } else if (orientation == 2) {
        M0 = IN[2];
        M1 = IN[3];
        M2 = IN[0];
        M3 = IN[1];
    } else if (orientation == 3) {
        M0 = IN[3];
        M1 = IN[0];
        M2 = IN[1];
        M3 = IN[2];
    }

    OUT.push_back(M0);
    OUT.push_back(M1);
    OUT.push_back(M2);
    OUT.push_back(M3);
}

float QRDetector::cross(cv::Point2f v1, cv::Point2f v2) {
    return v1.x * v2.y - v1.y * v2.x;
}