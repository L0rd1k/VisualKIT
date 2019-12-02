/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsCollectorBase.h
 * Author: ilya
 *
 * Created on November 19, 2019, 1:57 PM
 */

#ifndef POINTSCOLLECTORBASE_H
#define POINTSCOLLECTORBASE_H

#include <vector>
#include "opencv2/core/core.hpp"

typedef std::vector<cv::Point2f> Points2f;
typedef std::vector<cv::Point3f> Points3f;

class PointsCollectorBase {
public:
    virtual ~PointsCollectorBase() {}
    virtual Points3f collectObjectPoints() = 0;
    virtual Points2f collectFramePoints(cv::Mat &image) = 0;
    virtual cv::Size getChessboardSize() = 0;
    virtual void collectKeypoints(cv::Mat &image, Points2f &framePoints, Points3f &objectPoints) {
        framePoints = collectFramePoints(image);
        objectPoints = collectObjectPoints();
    }
};


#endif /* POINTSCOLLECTORBASE_H */

