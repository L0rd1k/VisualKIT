/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsCollectorCircles.cpp
 * Author: ilya
 * 
 * Created on November 19, 2019, 1:53 PM
 */

#include "PointsCollectorCircles.h"

#include "opencv2/core/core.hpp"
#include "opencv2/calib3d.hpp"

#include <iostream>

using namespace std;
using namespace cv;

PointsCollectorCircles::PointsCollectorCircles(int x, int y, int size, bool isAsymmetric) {
    this->chessboardSize = Size(x, y);
    this->squareSize = size;
    this->isAsymmetric = isAsymmetric;
}

PointsCollectorCircles::~PointsCollectorCircles() {
}

Points2f PointsCollectorCircles::collectFramePoints(Mat &image) {
    Points2f pts;
    int flags;
    if (isAsymmetric) {
        flags = CALIB_CB_ASYMMETRIC_GRID | CALIB_CB_CLUSTERING;
    } else {
        flags = CALIB_CB_SYMMETRIC_GRID;
    }
    bool circlesResult = findCirclesGrid(image, chessboardSize, pts, flags);
    if (!circlesResult) {
        pts.clear();
    }
    return pts;
}

Points3f PointsCollectorCircles::collectObjectPoints() {
    Points3f tmpObjectPoints;
    float curShift = 0;
    int heightSize = squareSize;
    if (this->isAsymmetric) {
        heightSize /= 2;
    }
    int i = 0;
    for (int y = 0; y < chessboardSize.height; y++) {
        if (this->isAsymmetric) {
            if (i % 2 == 0) {
                curShift = 0;
            } else {
                curShift = squareSize / 2;
            }
        }
        i++;
        for (int x = 0; x < chessboardSize.width; x++) {
            Point3f tmpObjectPoint(x * squareSize + curShift, y * heightSize, 0);
            tmpObjectPoints.push_back(tmpObjectPoint);
        }
    }
    return tmpObjectPoints;
}

cv::Size PointsCollectorCircles::getChessboardSize() {
    return chessboardSize;
}
