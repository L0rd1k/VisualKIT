/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraCalibration.h
 * Author: ilya
 *
 * Created on November 21, 2019, 11:39 AM
 */

#ifndef CAMERACALIBRATION_H
#define CAMERACALIBRATION_H


#include "Utils/Calibration/PointsCollectorBase.h"
#include "Utils/Calibration/PointsCollectorChess.h"
#include "Utils/Calibration/PointsCollectorCircles.h"

#include <iostream>
#include <vector>


#ifndef QT_INCLUDE
#include <QFileDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#endif

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#endif

class CameraCalibration : public QWidget {
    Q_OBJECT
public:
    CameraCalibration();
    virtual ~CameraCalibration();
private:
    QString folderPath;
    QStringList files;
    PointsCollectorBase *obj_pointsCollector;
    std::ostringstream oss;
public:
    QString saveCalibrationResults(Mat m, Mat d, Size imageSize, double err);
    QStringList getImagesFromFolder(QString folderPath);
    QString getImagesFolder();
    std::tuple<double, cv::Mat, cv::Mat> collectCalibrationObjectPoints(PointsCollectorBase &obj_pointsCollector, vector< vector<Point2f> > imagesPoints, Size imageSize);
};

#endif /* CAMERACALIBRATION_H */

