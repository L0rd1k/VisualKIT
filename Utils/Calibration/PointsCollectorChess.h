/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsCollectorChess.h
 * Author: ilya
 *
 * Created on November 19, 2019, 1:51 PM
 */

#ifndef POINTSCOLLECTORCHESS_H
#define POINTSCOLLECTORCHESS_H

#include "PointsCollectorBase.h"
#include "utils.h"

#include "opencv2/core/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

class PointsCollectorChess : public PointsCollectorBase {
public:
    PointsCollectorChess(int x = 9, int y = 6, int size = 25);
    virtual ~PointsCollectorChess();
    Points3f collectObjectPoints() override;
    Points2f collectFramePoints(cv::Mat &image) override;
    cv::Size getChessboardSize() override;
private:
    cv::Size chessboardSize;
    float squareSize;
};


#endif /* POINTSCOLLECTORCHESS_H */

