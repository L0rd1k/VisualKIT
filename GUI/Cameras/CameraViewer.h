/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraViewer.h
 * Author: Ilya Petrikov
 *
 * Created on December 3, 2019, 4:23 PM
 */

#ifndef _CAMERAVIEWER_H
#define _CAMERAVIEWER_H

#include "ui_CameraViewer.h"
#include <cstdlib> 
#include <ctime>

#ifndef QT_INCUDE
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QElapsedTimer>
#include <QPainter> 
#endif

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#endif

class CameraViewer : public QWidget {
    Q_OBJECT
public:
    CameraViewer();
    virtual ~CameraViewer();
public slots:
    void setFrame(cv::Mat);
private:
    Ui::CameraViewer *widget = NULL;
};

#endif /* _CAMERAVIEWER_H */
