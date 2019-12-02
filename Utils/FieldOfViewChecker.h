/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FieldOfViewChecker.h
 * Author: ilya
 *
 * Created on November 19, 2019, 12:49 PM
 */

#ifndef FIELDOFVIEWCHECKER_H
#define FIELDOFVIEWCHECKER_H

#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace cv;
using namespace std;

enum class FovAxis {
    X,
    Y
};

class FieldOfViewChecker {
public:
    FieldOfViewChecker(cv::Mat matrixIntrinsics);
    virtual ~FieldOfViewChecker();
    double getFov(int resolution, FovAxis axis);
    double getResolution(double fov, FovAxis axis);
    double getFocalLength(double);
    void openCalib( std::string filename, cv::Mat& matrix, cv::Mat& distortion, cv::Size& imgSize);
private:
    cv::Mat _m;
};

#endif /* FIELDOFVIEWCHECKER_H */

