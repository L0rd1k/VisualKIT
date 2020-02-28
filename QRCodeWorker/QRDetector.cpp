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

void QRDetector::captureVideo() {
    cv::VideoCapture captureVid(0);
    if (!captureVid.isOpened()) {
        std::cout << "Can't capture video by path: " + capturePath << std::endl;
    } else {
        captureVid >> originalImage;
        mark = cv::Mat(originalImage.size(), CV_8UC3);
        while (true) {
            initializeQrValues();
            marker = 0;
            captureVid >> originalImage;
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
    cv::Canny(grayImage, edgesImage, 100, 200, 3);
    cv::findContours(edgesImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    for (unsigned int i = 0; i < contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
    }
    cv::imshow("Contours", drawing);
}

float QRDetector::EuclideanDistance(cv::Point2f pnt1, cv::Point2f pnt2) {
    return sqrt(pow(abs(pnt1.x - pnt2.x), 2) + pow(abs(pnt1.y - pnt2.y), 2));
}

void QRDetector::approximateContours(std::vector<cv::Point2f> contoursMassCenter) {
    cv::Mat approxDraw = cv::Mat::zeros(edgesImage.size(), CV_8UC3);
    for (unsigned int i = 0; i < contours.size(); i++) {
        cv::approxPolyDP(contours[i], pointsSequence, cv::arcLength(contours[i], true) * 0.02, true);
        if (pointsSequence.size() == 4) {
            approximatedContours.push_back(pointsSequence);
            int currentIndex = i;
            int vCounter = 0;

            // Check in case child contour is found
            while (hierarchy[currentIndex][2] != -1) {
                currentIndex = hierarchy[currentIndex][2];
                vCounter++;
            }
            if (hierarchy[currentIndex][2] != -1) {
                vCounter++;
            }
            if (vCounter >= 5) {
                switch (marker) {
                    case 0:
                        A = i;
                        break;
                    case 1:
                        B = i;
                        break;
                    case 2:
                        C = i;
                        break;
                }
                marker++;
            }
        }
    }

    if (marker >= 3) {
        std::map<unsigned int, float> distanceMap;
        std::vector<std::pair<int, int> > contourPair{
            {A, B},
            {B, C},
            {C, A}};
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        for (unsigned int i = 0; i < contourPair.size(); i++) {
            cv::line(originalImage, contoursMassCenter[contourPair[i].first], contoursMassCenter[contourPair[i].second], color, 3);
            distanceMap.insert(std::make_pair(i, EuclideanDistance(contoursMassCenter[contourPair[i].first], contoursMassCenter[contourPair[i].second])));
        }

        for (auto &i : distanceMap) {
            std::cout << i.first << " = " << i.second << " ";
        }
        std::cout << std::endl;
    }
    cv::imshow("Points", originalImage);

    if (approximatedContours.size() > 0) {
        for (unsigned int i = 0; i < approximatedContours.size(); i++) {
            cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
            cv::drawContours(approxDraw, approximatedContours, i, color, 2, 8, hierarchy, 0, cv::Point());
        }
        cv::imshow("Approximated Contours", approxDraw);
        approximatedContours.clear();
    }
}