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
#include "FieldOfViewWindow.h"
#include "Calibration/SingleCameraCalibration.h"
#include <QDebug>
#include <memory>

class MainMenuWindow : public QWidget {
    Q_OBJECT
public:
    MainMenuWindow();
    virtual ~MainMenuWindow();
private:
    void removeAllElementsFromLayout(QLayout* layout);
private:
    Ui::MainMenuWindow *widget = NULL;
    FieldOfViewWindow *obj_fov = NULL;
    SingleCameraCalibration *obj_singleCalib = NULL;
private slots:
    void regime_CalculateFoV();
    void regime_CalculateSingleCalib();
    
};
#endif /* _MAINMENUWINDOW_H */
