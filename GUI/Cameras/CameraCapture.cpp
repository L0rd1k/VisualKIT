/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraCapture.cpp
 * Author: Ilya Petrikov
 * 
 * Created on February 14, 2020, 10:49 AM
 */

#include "CameraCapture.h"

CameraCapture::CameraCapture(QString capturePath) : capPath(capturePath) {
}

void CameraCapture::readVideo() {
    if (capPath == "0")
        cap.open(0);
    else
        cap.open(capPath.toStdString());
    
    if (!cap.isOpened()) {
        qDebug() << "Can't open video file " << capPath;
        emit finished();
    }
    
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            emit frameFinished(frame);
            break;
        }
        emit frameFinished(frame.clone());
    }
    emit finished();
}

CameraCapture::~CameraCapture() {
}

