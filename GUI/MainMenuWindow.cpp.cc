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

void MainMenuWindow::SelectUsedExtensions() {
    obj_calibExecutor = new CalibrationExecutor();
    widget->horizontalLayout->addWidget(obj_calibExecutor, 10);
}

MainMenuWindow::MainMenuWindow() : widget(new Ui::MainMenuWindow) {
    widget->setupUi(this);
}

MainMenuWindow::~MainMenuWindow() {
    delete widget;
    delete obj_calibExecutor;
    delete obj_camViewer;
}