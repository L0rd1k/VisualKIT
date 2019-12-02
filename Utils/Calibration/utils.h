/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: ilya
 *
 * Created on November 19, 2019, 2:03 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include <opencv2/core.hpp>
#include "opencv2/imgproc.hpp"

class utils {
public:
    utils();
    virtual ~utils();
private:

};

cv::Mat convToGray(const cv::Mat& in);

#endif /* UTILS_H */

