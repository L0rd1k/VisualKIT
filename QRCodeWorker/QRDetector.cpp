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
    drawing = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    for (unsigned int i = 0; i < contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
    }
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
    approxDraw = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    if (approximatedContours.size() > 0) {
        for (unsigned int i = 0; i < approximatedContours.size(); i++) {
            cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            cv::drawContours(approxDraw, approximatedContours, i, color, 2, 8, hierarchy, 0, cv::Point());
        }
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
                        cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255, 255));
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
                cv::Point2f searchingPoint;
                std::vector<cv::Point2f> source, destination;
                cv::Mat warpingImage;

                getMarksVerticies(contours, topValue, slope, tempLeftTop);
                getMarksVerticies(contours, rightValue, slope, tempRightTop);
                getMarksVerticies(contours, bottomValue, slope, tempLeftDown);

                verifyCornerPosition(orientation, tempLeftTop, leftTop);
                verifyCornerPosition(orientation, tempRightTop, rightTop);
                verifyCornerPosition(orientation, tempLeftDown, leftDown);

                findItersectionPoint(rightTop[1], rightTop[2], leftDown[3], leftDown[2], searchingPoint);

                //TOP POINTS
                source.push_back(leftTop[0]);
                source.push_back(rightTop[1]);
                source.push_back(searchingPoint);
                source.push_back(leftDown[3]);


                destination.push_back(cv::Point2f(0, 0));
                destination.push_back(cv::Point2f(qrValue.cols, 0));
                destination.push_back(cv::Point2f(qrValue.cols, qrValue.rows));
                destination.push_back(cv::Point2f(0, qrValue.rows));

                if (source.size() == 4 && destination.size() == 4) {
                    warpingImage = cv::getPerspectiveTransform(source, destination);
                    cv::warpPerspective(originalImage, qrRawValue, warpingImage, cv::Size(qrValue.cols, qrValue.rows));
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
    cv::Mat img1 = imgOpr.tieImagesHorizontaly(testImage, originalImage);
    cv::Mat img2 = imgOpr.tieImagesHorizontaly(drawing, approxDraw);
    cv::imshow("Image", imgOpr.tieImagesVerticaly(img1, img2));
}

bool QRDetector::findItersectionPoint(cv::Point2f pnt1, cv::Point2f pnt2, cv::Point2f pnt3, cv::Point2f pnt4, cv::Point2f& intersection) {
    cv::Point2f topRight = pnt1;
    cv::Point2f leftBottom = pnt3;
    cv::Point2f r(pnt2 - pnt1);
    cv::Point2f s(pnt4 - pnt3);
    if (calculateCrossedPoint(r, s) == 0)
        return false;
    float t = calculateCrossedPoint(leftBottom - topRight, s) / calculateCrossedPoint(r, s);
    intersection = topRight + t*r;
    cv::line(testImage, intersection, intersection, cv::Scalar(0, 255, 255), 7);
    return true;
}

std::vector<cv::Point2f> QRDetector::getBoxPointsCoordinates(cv::Rect markerBox) {
    std::vector<cv::Point2f> boxCoordinatesVector;
    boxCoordinatesVector.push_back(cv::Point2f(markerBox.tl()));
    boxCoordinatesVector.push_back(cv::Point2f(markerBox.br().x, markerBox.tl().y));
    boxCoordinatesVector.push_back(cv::Point2f(markerBox.br()));
    boxCoordinatesVector.push_back(cv::Point2f(markerBox.tl().x, markerBox.br().y));
    return boxCoordinatesVector;
}

std::vector<cv::Point2f> QRDetector::getMiddleBoxPointsCoorinates(std::vector<cv::Point2f> boxCoordinatesVector) {
    std::vector<cv::Point2f> qrCoordinatesVector;
    qrCoordinatesVector.push_back(
            cv::Point2f((boxCoordinatesVector[0].x + boxCoordinatesVector[1].x) / 2,
            boxCoordinatesVector[0].y));
    qrCoordinatesVector.push_back(
            cv::Point2f(boxCoordinatesVector[1].y,
            (boxCoordinatesVector[1].y + boxCoordinatesVector[2].y) / 2));
    qrCoordinatesVector.push_back(
            cv::Point2f((boxCoordinatesVector[2].x + boxCoordinatesVector[3].x) / 2,
            boxCoordinatesVector[3].y));
    qrCoordinatesVector.push_back(
            cv::Point2f(boxCoordinatesVector[3].x,
            (boxCoordinatesVector[3].y + boxCoordinatesVector[0].y) / 2));
    return qrCoordinatesVector;
}

void QRDetector::getMarksVerticies(std::vector<std::vector<cv::Point> > contours, int contoursId, float slope, std::vector<cv::Point2f>& quadraticValue) {
    cv::Rect markerBox = cv::boundingRect(contours[contoursId]);
    cv::rectangle(testImage, markerBox, cv::Scalar(0, 255, 0));
    std::vector<cv::Point2f> boxCoordinatesVector = getBoxPointsCoordinates(markerBox);
    std::vector<cv::Point2f> qrCoordinatesVector = getMiddleBoxPointsCoorinates(boxCoordinatesVector);
    cv::Point2f M0, M1, M2, M3;
    std::vector<cv::Point2f> identificationVec = {M0, M1, M2, M3};
    float dmax[4] = {0};
    if (slope > 5 || slope < -5) {
        for (unsigned int i = 0; i < contours[contoursId].size(); i++) {
            float perDistance_1 = calculatePerpendicularPointsDistance(boxCoordinatesVector[2], boxCoordinatesVector[0], contours[contoursId][i]);
            float perDistance_2 = calculatePerpendicularPointsDistance(boxCoordinatesVector[1], boxCoordinatesVector[3], contours[contoursId][i]);
            if ((perDistance_1 >= 0.0) && (perDistance_2 > 0.0)) {
                updateCorner(contours[contoursId][i], qrCoordinatesVector[0], dmax[1], identificationVec[1]);
            } else if ((perDistance_1 > 0.0) && (perDistance_2 <= 0.0)) {
                updateCorner(contours[contoursId][i], qrCoordinatesVector[1], dmax[2], identificationVec[2]);
            } else if ((perDistance_1 <= 0.0) && (perDistance_2 < 0.0)) {
                updateCorner(contours[contoursId][i], qrCoordinatesVector[2], dmax[3], identificationVec[3]);
            } else if ((perDistance_1 < 0.0) && (perDistance_2 >= 0.0)) {
                updateCorner(contours[contoursId][i], qrCoordinatesVector[3], dmax[0], identificationVec[0]);
            } else
                continue;
        }
    } else {
        int halfx = (boxCoordinatesVector[0].x + boxCoordinatesVector[1].x) / 2;
        int halfy = (boxCoordinatesVector[0].y + boxCoordinatesVector[3].y) / 2;
        for (unsigned int i = 0; i < contours[contoursId].size(); i++) {
            if ((contours[contoursId][i].x < halfx) && (contours[contoursId][i].y <= halfy)) {
                updateCorner(contours[contoursId][i], boxCoordinatesVector[2], dmax[2], identificationVec[0]);
            } else if ((contours[contoursId][i].x >= halfx) && (contours[contoursId][i].y < halfy)) {
                updateCorner(contours[contoursId][i], boxCoordinatesVector[3], dmax[3], identificationVec[1]);
            } else if ((contours[contoursId][i].x > halfx) && (contours[contoursId][i].y >= halfy)) {
                updateCorner(contours[contoursId][i], boxCoordinatesVector[0], dmax[0], identificationVec[2]);
            } else if ((contours[contoursId][i].x <= halfx) && (contours[contoursId][i].y > halfy)) {
                updateCorner(contours[contoursId][i], boxCoordinatesVector[1], dmax[1], identificationVec[3]);
            }
        }
    }
    for (auto elem : identificationVec) {
        //        cv::line(testImage, elem, elem, cv::Scalar(255, 255, 0), 3, 16);
        quadraticValue.push_back(elem);
    }
}

void QRDetector::updateCorner(cv::Point2f P, cv::Point2f ref, float& baseline, cv::Point2f& corner) {
    float temp_dist;
    temp_dist = EuclideanDistance(P, ref);
    if (temp_dist > baseline) {
        baseline = temp_dist; // The farthest distance is the new baseline
        corner = P; // P is now the farthest point
    }
}

void QRDetector::verifyCornerPosition(int orientation, std::vector<cv::Point2f> IN, std::vector<cv::Point2f> &Result) {
    cv::Point2f M0, M1, M2, M3;
    std::vector<cv::Point2f> pointVec = {M0, M1, M2, M3};
    switch (orientation) {
        case 0:
            pointVec[0] = IN[0];
            pointVec[1] = IN[1];
            pointVec[2] = IN[2];
            pointVec[3] = IN[3];
            break;
        case 1:
            pointVec[0] = IN[1];
            pointVec[1] = IN[2];
            pointVec[2] = IN[3];
            pointVec[3] = IN[0];
            break;
        case 2:
            pointVec[0] = IN[2];
            pointVec[1] = IN[3];
            pointVec[2] = IN[0];
            pointVec[3] = IN[1];
            break;
        case 3:
            pointVec[0] = IN[3];
            pointVec[1] = IN[0];
            pointVec[2] = IN[1];
            pointVec[3] = IN[2];
            break;
        default:
            break;
    }
    for (auto elem : pointVec) {
        Result.push_back(elem);
    }
}

float QRDetector::calculateCrossedPoint(cv::Point2f v1, cv::Point2f v2) {
    return v1.x * v2.y - v1.y * v2.x;
}
