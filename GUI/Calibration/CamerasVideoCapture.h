/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CamerasVideoCapture.h
 * Author: Ilya Petrikov
 *
 * Created on December 27, 2019, 1:20 PM
 */

#ifndef _CAMERASVIDEOCAPTURE_H
#define _CAMERASVIDEOCAPTURE_H

#include "ui_CamerasVideoCapture.h"
#include "../Cameras/CameraViewer.h"
#include "../Cameras/CameraCapture.h"

#include <memory>

#include <QSettings>
#include <QDebug>
#include <QThread>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#endif

class CamerasVideoCapture : public QWidget {
    Q_OBJECT
public:
    CamerasVideoCapture();
    virtual ~CamerasVideoCapture();
private slots:
    void getCameraFrame();
    void removeDevice();
    void addNewDevice();
private:
    Ui::CamerasVideoCapture *widget = nullptr;
    QTableWidgetItem *iCheck = nullptr;
    QVector<QThread*> threads;
    QVector<QString> vec_values;
    QVector<QString> activePath;
    QStringList keys;
    QMap <int, QPushButton*> mapDelete;
    QSettings* settings = nullptr;
private:
    QVector<QString> getIniCameraConfigurations();
    void addVideoPathToComboBox(QVector<QString> &iniConf);
    void removeAllElementsFromLayout(QLayout* layout);
    void setHeaderConfiguration();
    void getCheckedCameras();
};

#endif /* _CAMERASVIDEOCAPTURE_H */
