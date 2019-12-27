/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FieldOfViewWindow.h
 * Author: Ilya Petrikov
 *
 * Created on December 16, 2019, 11:12 AM
 */

#ifndef _FIELDOFVIEWWINDOW_H
#define _FIELDOFVIEWWINDOW_H

#include "ui_FieldOfViewWindow.h"
#include "Utils/FieldOfViewChecker.h"

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#endif

#include <QFileDialog>
#include <fstream>
#include <string>
#include <exception>

class FieldOfViewWindow : public QWidget {
    Q_OBJECT
public:
    FieldOfViewWindow();
    virtual ~FieldOfViewWindow();
private:
    Ui::FieldOfViewWindow *widget = NULL;
    QString folderPath;
    std::string filename;
private:
    std::ifstream::pos_type getFileSize(const char* filename);
private slots:
    bool openFolderWithIntrinsics(cv::Mat& matrix, cv::Mat& distortion, cv::Size & imgSize);
    void calculateFieldOfView();
};

#endif /* _FIELDOFVIEWWINDOW_H */
