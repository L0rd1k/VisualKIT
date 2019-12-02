/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ImageViewer.cpp
 * Author: ilya
 *
 * Created on November 22, 2019, 3:25 PM
 */

#include "ImageViewer.h"
#include "ui_ImageViewer.h"

ImageViewer::ImageViewer() : widget(new Ui::ImageViewer){
    widget->setupUi(this);
}

void ImageViewer::setFrame(cv::Mat cornersImage) {
    QImage tempHudImage((uchar*) cornersImage.data, cornersImage.cols, cornersImage.rows, cornersImage.step, QImage::Format_RGB888);
    tempHudImage.scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio);
    QPixmap resultPixmap(tempHudImage.size());
    QPainter p(&resultPixmap);
    p.drawPixmap(0, 0, QPixmap::fromImage(tempHudImage));
    widget->ImageLabel->setPixmap(QPixmap::fromImage(tempHudImage).scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation)); //, Qt::KeepAspectRatio, Qt::FastTransformation
}

ImageViewer::~ImageViewer() {
    delete widget;
}
