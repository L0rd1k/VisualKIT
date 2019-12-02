/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsCollectorCircles.h
 * Author: ilya
 *
 * Created on November 19, 2019, 1:53 PM
 */

#ifndef POINTSCOLLECTORCIRCLES_H
#define POINTSCOLLECTORCIRCLES_H

#include "PointsCollectorBase.h"

class PointsCollectorCircles : public PointsCollectorBase {
public:
    PointsCollectorCircles(int x = 4, int y = 11, int size = 44, bool isAsymmetric = true);
    virtual ~PointsCollectorCircles();
    Points3f collectObjectPoints() override;
    Points2f collectFramePoints(cv::Mat &image) override;
    cv::Size getChessboardSize() override;
private:
    cv::Size chessboardSize;
    float squareSize;
    bool isAsymmetric;
};

#endif /* POINTSCOLLECTORCIRCLES_H */

