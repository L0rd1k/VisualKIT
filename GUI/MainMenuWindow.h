/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuWindow.h
 * Author: ilya
 *
 * Created on November 15, 2019, 1:33 PM
 */

#ifndef _MAINMENUWINDOW_H
#define _MAINMENUWINDOW_H

#include "ui_MainMenuWindow.h"
#include "CalibrationExecutor.h"
#include "Cameras/CameraViewer.h"
#include <QDebug>
#include <memory>

class MainMenuWindow : public QWidget {
    Q_OBJECT
public:
    MainMenuWindow();
    virtual ~MainMenuWindow();
private:
    void SelectUsedExtensions();
private:
    Ui::MainMenuWindow *widget = NULL;
    CalibrationExecutor *obj_calibExecutor = NULL;
    CameraViewer *obj_camViewer = NULL;
};
#endif /* _MAINMENUWINDOW_H */
