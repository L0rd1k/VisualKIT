/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QRDetector.h
 * Author: Ilya Petrikov
 *
 * Created on February 28, 2020, 1:09 PM
 */

#ifndef QRDETECTOR_H
#define QRDETECTOR_H

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>

enum class QROrientation {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

class QRDetector {
public:
    QRDetector();
    virtual ~QRDetector();
    void captureVideo();
private:
    void initializeQrValues();
    void findAllContours();
    void getMoments();
    void approximateContours(std::vector<cv::Point2f> contoursMassCenter);
    float EuclideanDistance(cv::Point2f pnt1, cv::Point2f pnt2);
    float calculatePerpendicularPointsDistance(cv::Point2f medianFirst, cv::Point2f medianSecond, cv::Point2f diagonal);
    void slopeIdentification(std::map<std::string, float> distanceMap, std::vector<cv::Point2f> contoursMassCenter);
    void drawApproximatedContours();
    void resetCalculatedValues();
    std::vector<cv::Point2f> getBoxPointsCoordinates(cv::Rect markerBox);
    std::vector<cv::Point2f> getMiddleBoxPointsCoorinates(std::vector<cv::Point2f> boxCoordinatesVector);
    float longestSideSlope(cv::Point2f point1, cv::Point2f point2, int& aligner);
    void getMarksVerticies(std::vector<std::vector<cv::Point> > contours, int contoursId, float slope, std::vector<cv::Point2f>& quadraticValue);
    void updateCorner(cv::Point2f P, cv::Point2f ref, float& baseline, cv::Point2f& corner);
    void verifyCornerPosition(int orientation, std::vector<cv::Point2f> IN, std::vector<cv::Point2f> &OUT);
    float cross(cv::Point2f v1, cv::Point2f v2);
    bool findItersectionPoint(cv::Point2f a1, cv::Point2f a2, cv::Point2f b1, cv::Point2f b2, cv::Point2f& intersection);
private:
    std::string capturePath;
    cv::Mat originalImage;
    cv::Mat testImage;
    cv::Mat grayImage;
    cv::Mat edgesImage;
    cv::Mat mark;
    cv::Mat qrRawValue, qrValue, qrGray, qrThreshold;
    cv::RNG rng;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<std::vector<cv::Point> > approximatedContours;
    std::vector<cv::Vec4i> hierarchy;
    std::vector<cv::Point> pointsSequence;
    int counter = 0;
    int marker = 0;
    int A = 0, B = 0, C = 0;
    int diagonalValue = 0, medianValueFirst = 0, medianValueSecond = 0;
    float distance = 0.f, slope = 0.f;
    int aligner = 0, orientation = 0;

    unsigned int topValue = 0, rightValue = 0, bottomValue = 0;

};

#endif /* QRDETECTOR_H */

