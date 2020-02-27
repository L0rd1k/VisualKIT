/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CameraViewer.cpp
 * Author: Ilya Petrikov
 *
 * Created on December 3, 2019, 4:23 PM
 */

#include "CameraViewer.h"

CameraViewer::CameraViewer() : widget(new Ui::CameraViewer) {
    widget->setupUi(this);
}

void CameraViewer::setFrame(cv::Mat cornersImage) {
    QImage tempHudImage((uchar*) cornersImage.data, cornersImage.cols, cornersImage.rows, cornersImage.step, QImage::Format_RGB888);
    tempHudImage = tempHudImage.rgbSwapped();
    tempHudImage.scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio);
    QPixmap resultPixmap(tempHudImage.size());
    QPainter p(&resultPixmap);
    p.drawPixmap(0, 0, QPixmap::fromImage(tempHudImage));
    widget->ImageLabel->setPixmap(QPixmap::fromImage(tempHudImage).scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation)); //, Qt::KeepAspectRatio, Qt::FastTransformation
}

CameraViewer::~CameraViewer() {
    delete widget;
}