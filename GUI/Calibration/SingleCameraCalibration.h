/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SingleCameraCalibration.h
 * Author: Ilya Petrikov
 *
 * Created on December 20, 2019, 2:01 PM
 */

#ifndef _SINGLECAMERACALIBRATION_H
#define _SINGLECAMERACALIBRATION_H

#include "ui_SingleCameraCalibration.h"

#include "Utils/Calibration/PointsCollectorBase.h"
#include "Utils/Calibration/PointsCollectorChess.h"
#include "Utils/Calibration/PointsCollectorCircles.h"
#include "Utils/Calibration/CameraCalibration.h"
#include "../Cameras/ImageViewer.h"

#include <memory>
#include <iostream>

#ifndef QT_INCUDE
#include <QAction>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QLabel>
#include <QElapsedTimer>
#include <QDateTime>
#include <QPainter> 
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QDesktopServices>
#include <QLayoutItem>
#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QTextCodec>
#include <QLocale>
#include <QTranslator>
#include <QHeaderView>
#endif

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#endif

struct PatternConfig {
public:
    int calib_horizontal_val;
    int calib_vertical_val;
    double calib_size_val;
public:
    PatternConfig(int chv, int cvv, double csv) :
    calib_horizontal_val(chv),
    calib_vertical_val(cvv),
    calib_size_val(csv) {
    }
};

class SingleCameraCalibration : public QWidget {
    Q_OBJECT
public:
    SingleCameraCalibration();
    virtual ~SingleCameraCalibration();
    void removeAllElementsFromLayout(QLayout* layout);
    void checkCurrentPatternToUse();
    void calibrationTableHeader();
    void calibrationTableInfo(int id, int currentRow, QString status);
private:
    void setDefaultCircleValue();
    void setDefaultChessboardValue();
    void clearLabels();
private slots:
    void cameraCalibration();
    void selectCheckboxChessboard();
    void selectCheckboxCircle();
private:
    cv::Size imageSize;
    int counterImageFound = 0;
    PatternConfig *patternConf = NULL;
    CameraCalibration* obj_cameraCalibration = NULL;
    QString folderPath;
    QStringList imagesFromFolder;
    QStringList tableHeader;
    vector< vector<Point2f> > imagesPoints;
    std::tuple<double, cv::Mat, cv::Mat> calibrationError;
    std::unique_ptr<PointsCollectorBase> obj_pointsCollector;
private:
    Ui::SingleCameraCalibration *widget = NULL;
};

#endif /* _SINGLECAMERACALIBRATION_H */
