/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageOperations.cpp
 * Author: Ilya Petrikov
 * 
 * Created on March 6, 2020, 1:48 PM
 */

#include "ImageOperations.h"

ImageOperations::ImageOperations() {
}

int ImageOperations::concatinatingMat(const cv::Mat& img1C, const cv::Mat& img2C, cv::Mat& img1, cv::Mat& img2) {
    img1 = img1C;
    img2 = img2C;
    int type = img1.type();
    if (img1.type() != img2.type()) {
        if (img1.type() == CV_8UC1 && img2.type() == CV_8UC3) {
            cv::cvtColor(img1, img1, CV_GRAY2BGR);
            type = CV_8UC3;
        } else if (img2.type() == CV_8UC1 && img1.type() == CV_8UC3) {
            cv::cvtColor(img2, img2, CV_GRAY2BGR);
            type = CV_8UC3;
        } else {
            assert(1);
        }
    }
    return type;
}

cv::Mat ImageOperations::tieImagesHorizontaly(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat tempImg1;
    cv::Mat tempImg2;
    int type = concatinatingMat(img1, img2, tempImg1, tempImg2);
    if (tempImg1.empty()) {
        return tempImg2;
    } else if (tempImg2.empty()) {
        return tempImg1;
    }
    cv::Size size(tempImg1.cols + tempImg2.cols, cv::max(tempImg1.rows, tempImg2.rows));
    cv::Mat img = cv::Mat::zeros(size, type);
    
    cv::Rect roi1(cv::Point(0, 0), tempImg1.size());
    cv::Rect roi2(cv::Point(tempImg1.cols, 0), tempImg2.size());
    tempImg1.copyTo(img(roi1));
    tempImg2.copyTo(img(roi2));
    return img;
}

cv::Mat ImageOperations::tieImagesVerticaly(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat tempImg1;
    cv::Mat tempImg2;
    int type = concatinatingMat(img1, img2, tempImg1, tempImg2);
    if (tempImg1.empty()) {
        return tempImg2;
    } else if (tempImg2.empty()) {
        return tempImg1;
    }
    cv::Size size(cv::max(tempImg1.cols, tempImg2.cols), tempImg1.rows + tempImg2.rows);
    cv::Mat img = cv::Mat::zeros(size, type);
    cv::Rect roi1(cv::Point(0, 0), tempImg1.size());
    cv::Rect roi2(cv::Point(0, tempImg1.rows), tempImg2.size());
    tempImg1.copyTo(img(roi1));
    tempImg2.copyTo(img(roi2));
    return img;
}

ImageOperations::~ImageOperations() {
}

