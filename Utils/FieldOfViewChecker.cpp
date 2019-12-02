/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FieldOfViewChecker.cpp
 * Author: ilya
 * 
 * Created on November 19, 2019, 12:49 PM
 */

#include "FieldOfViewChecker.h"

FieldOfViewChecker::FieldOfViewChecker(Mat matrixIntrinsics)
: _m(matrixIntrinsics) {
}

double FieldOfViewChecker::getFov(int resolution, FovAxis axis) {
    int axisId = (int) axis;
    double focal_distance = _m.at<double>(axisId, axisId);
    return 2 * atan(resolution / (2 * focal_distance)) * (180.0 / CV_PI);
}

double FieldOfViewChecker::getResolution(double fov, FovAxis axis) {
    int axisId = (int) axis;
    double fov_rad = fov * CV_PI / 180;
    return 2 * _m.at<double>(axisId, axisId) * tan(fov_rad / 2);
}

FieldOfViewChecker::~FieldOfViewChecker() {
}

