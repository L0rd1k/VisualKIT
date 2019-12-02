/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsCollectorChess.cpp
 * Author: ilya
 * 
 * Created on November 19, 2019, 1:51 PM
 */

#include "PointsCollectorChess.h"

PointsCollectorChess::PointsCollectorChess(int x, int y, int size) {
    chessboardSize = Size(x, y);
    squareSize = size;
}

PointsCollectorChess::~PointsCollectorChess() {
}

Points3f PointsCollectorChess::collectObjectPoints() {
    Points3f tmpObjectPoints;
    //    Point3f shift(-tvec.at<double>(0), tvec.at<double>(1), 0);
    Point3f shift(0, 0, 0);
    //            Point3f shift(230,280,0);
    for (int y = 0; y < chessboardSize.height; y++) {
        for (int x = 0; x < chessboardSize.width; x++) {
            Point3f tmpObjectPoint(x*squareSize, y*squareSize, 0);
            tmpObjectPoints.push_back(tmpObjectPoint + shift);
        }
    }
    return tmpObjectPoints;
}

Points2f PointsCollectorChess::collectFramePoints(cv::Mat &image) {
    Points2f pts;
    cv::Mat gray = convToGray(image);
    //    Timer tFrame;
    //    cout << "calc time7: " << tFrame.elapsedMs() << endl; tFrame.reset();
    for (double p = -4; p <= 0; p++) {
        Mat imageResized;
        double scale = std::pow(1.5, p);
        resize(gray, imageResized, Size(), scale, scale);
        bool chessboardResult = findChessboardCorners(imageResized, chessboardSize, pts,
                CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE | CV_CALIB_CB_ADAPTIVE_THRESH);
        if (chessboardResult) {
            for (auto& p : pts) {
                p.x /= scale;
                p.y /= scale;
            }
            cornerSubPix(gray, pts, Size(11, 11), Size(-1, -1),
                    TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
            //            cout << "found at scale=" << scale << ", pow=" << p << endl;
            break;
        } else {
            pts.clear();
        }
        //        imshow("gray", gray);
        //        cout << "pow=" << p << ", scale=" << scale <<  ", elapsed: " << tFrame.elapsed() << endl;
        //        waitKey(100);
        //        cout << "image.size(): " << imageResized.size() << endl;
    }
    //    cout << "calc time collectFramePoints: " << tFrame.elapsedMs() << endl; tFrame.reset();
    return pts;
}

cv::Size PointsCollectorChess::getChessboardSize() {
    return chessboardSize;
}
