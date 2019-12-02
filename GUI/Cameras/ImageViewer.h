/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageViewer.h
 * Author: ilya
 *
 * Created on November 22, 2019, 3:25 PM
 */

#ifndef _IMAGEVIEWER_H
#define _IMAGEVIEWER_H

#include "ui_ImageViewer.h"

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

class ImageViewer : public QWidget {
    Q_OBJECT
public:
    ImageViewer();
    virtual ~ImageViewer();
public slots:
    void setFrame(cv::Mat image);
private:
    Ui::ImageViewer *widget = NULL;
};

#endif /* _IMAGEVIEWER_H */
