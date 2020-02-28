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
private:
    std::string capturePath;
    cv::Mat originalImage;
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
    int marker;
    int A, B, C;
    float AB, BC, CA;

};

#endif /* QRDETECTOR_H */

