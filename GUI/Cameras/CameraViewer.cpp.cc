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

CameraViewer::CameraViewer(std::string fpath) : widget(new Ui::CameraViewer), path(fpath) {
    widget->setupUi(this);
}

void CameraViewer::setFrame(cv::Mat cornersImage) {
    QImage tempHudImage((uchar*) cornersImage.data, cornersImage.cols, cornersImage.rows, cornersImage.step, QImage::Format_RGB888);
    tempHudImage.scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio);
    QPixmap resultPixmap(tempHudImage.size());
    QPainter p(&resultPixmap);
    p.drawPixmap(0, 0, QPixmap::fromImage(tempHudImage));
    widget->ImageLabel->setPixmap(QPixmap::fromImage(tempHudImage).scaled(widget->ImageLabel->size(), Qt::KeepAspectRatio, Qt::FastTransformation)); //, Qt::KeepAspectRatio, Qt::FastTransformation
}

CameraViewer::~CameraViewer() {
    delete widget;
}

cv::VideoCapture CameraViewer::startCapturing() {
    if (path == "0") {
        capture.open(0);
    } else {
        capture.open(path);
    }
#define CAPTURE_PROP
#ifndef CAPTURE_PROP
    qDebug() << "FPS : " << capture.get(cv::CAP_PROP_FPS);
    qDebug() << "Width : " << capture.get(cv::CAP_PROP_FRAME_WIDTH);
    qDebug() << "Height : " << capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    int codecType = static_cast<int> (capture.get(CV_CAP_PROP_FOURCC));
    char codecTypeChar[] = {
        (char) (codecType & 0XFF),
        (char) ((codecType & 0XFF00) >> 8),
        (char) ((codecType & 0XFF0000) >> 16),
        (char) ((codecType & 0XFF000000) >> 24),
        0
    };
    qDebug() << "Codec type : " << codecTypeChar;
#endif
    return capture;
}

void CameraViewer::startStreaming() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(VideoStreaming()));
    timer->start(1);
}

cv::Mat CameraViewer::getFrameFromCapture() {
    capture >> frame;
    return frame;
}

void CameraViewer::VideoStreaming() {
    getFrameFromCapture();
    frameCounter++;
    if (frame.empty()) {
        qDebug() << "Frame is empty!";
        return;
    } else {
        cv::cvtColor(frame, frame, CV_BGR2RGB);
        setFrame(frame);
    }
}