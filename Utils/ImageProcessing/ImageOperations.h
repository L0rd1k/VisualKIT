/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageOperations.h
 * Author: Ilya Petrikov
 *
 * Created on March 6, 2020, 1:48 PM
 */

#ifndef IMAGEOPERATIONS_H
#define IMAGEOPERATIONS_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class ImageOperations {
public:
    ImageOperations();
    cv::Mat tieImagesVerticaly(const cv::Mat& img1, const cv::Mat& img2);
    cv::Mat tieImagesHorizontaly(const cv::Mat& img1, const cv::Mat& img2);
    int concatinatingMat(const cv::Mat& img1C, const cv::Mat& img2C, cv::Mat& img1, cv::Mat& img2);
    virtual ~ImageOperations();
private:

};

#endif /* IMAGEOPERATIONS_H */

