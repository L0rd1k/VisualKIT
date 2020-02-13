/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainMenuWindow.cpp
 * Author: ilya
 *
 * Created on November 15, 2019, 1:33 PM
 */

//#include <qt4/QtCore/qelapsedtimer.h>

#include "MainMenuWindow.h"

MainMenuWindow::MainMenuWindow() 
: widget(new Ui::MainMenuWindow) {
    widget->setupUi(this);
    connect(widget->pb_fov, SIGNAL(clicked(bool)), this, SLOT(regime_CalculateFoV()));
    connect(widget->pb_singlecalib, SIGNAL(clicked(bool)), this, SLOT(regime_CalculateSingleCalib()));
    connect(widget->pb_videostream, SIGNAL(clicked(bool)), this, SLOT(regime_CaptureStream()));
}

void MainMenuWindow::regime_CalculateFoV() {
    removeAllElementsFromLayout(widget->vl_execution);
    obj_fov = new FieldOfViewWindow();
    widget->vl_execution->addWidget(obj_fov, 10);
}

void MainMenuWindow::regime_CalculateSingleCalib() {
    removeAllElementsFromLayout(widget->vl_execution);
    obj_singleCalib = new SingleCameraCalibration();
    widget->vl_execution->addWidget(obj_singleCalib, 10);
}

void MainMenuWindow::regime_CaptureStream() {
    removeAllElementsFromLayout(widget->vl_execution);
    obj_videoStream = new CamerasVideoCapture();
    widget->vl_execution->addWidget(obj_videoStream, 10);
}

void MainMenuWindow::removeAllElementsFromLayout(QLayout* layout) {
    QLayoutItem* child;
    while (layout->count() != 0) {
        child = layout->takeAt(0);
        if (child->layout() != 0) {
            removeAllElementsFromLayout(child->layout());
        } else if (child->widget() != 0) {
            delete child->widget();
        }
        delete child;
    }
}

MainMenuWindow::~MainMenuWindow() {
    delete widget;
    delete obj_fov;
    delete obj_videoStream;
    delete obj_singleCalib;
}