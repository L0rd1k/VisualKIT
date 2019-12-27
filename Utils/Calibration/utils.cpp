/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.cpp
 * Author: ilya
 * 
 * Created on November 19, 2019, 2:03 PM
 */

#include "utils.h"

utils::utils() {
}

utils::~utils() {
}

cv::Mat convToGray(const cv::Mat& in) {
    cv::Mat out;
    if (in.channels() == 4)
        cvtColor(in, out, CV_BGRA2GRAY);
    else if (in.channels() == 3) {
        cvtColor(in, out, CV_BGR2GRAY);
    } else if (in.channels() == 1){
        in.copyTo(out);
    } else {
        std::cout << "Unsupported image type!" << std::endl;
    }
    return out;
}
