/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraCapture.h
 * Author: Ilya Petrikov
 *
 * Created on February 14, 2020, 10:49 AM
 */

#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H
#include <QObject>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QThread>

#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"

#include <unistd.h>

class CameraCapture : public QObject {
    Q_OBJECT
public:
    CameraCapture(QString capturePath);
    virtual ~CameraCapture();
public slots:
    void readVideo();
private:
    QString capPath;
    cv::VideoCapture cap;
    cv::Mat frame;
signals:
    void finished();
    void frameFinished(cv::Mat frame);
};

#endif /* CAMERACAPTURE_H */

