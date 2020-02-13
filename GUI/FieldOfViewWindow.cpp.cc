/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FieldOfViewWindow.cpp
 * Author: Ilya Petrikov
 *
 * Created on December 16, 2019, 11:12 AM
 */

#include "FieldOfViewWindow.h"

FieldOfViewWindow::FieldOfViewWindow() : widget(new Ui::FieldOfViewWindow) {
    widget->setupUi(this);
    widget->le_filename->setText("intrinsics");
    connect(widget->btn_calculateFOV, SIGNAL(clicked(bool)), this, SLOT(calculateFieldOfView()));
}

void FieldOfViewWindow::calculateFieldOfView() {
    folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    if (!folderPath.isEmpty()) {
        cv::Size imageSize;
        cv::Mat intrinsics, distortion;
        if (openFolderWithIntrinsics(intrinsics, distortion, imageSize)) {
            FieldOfViewChecker obj_fovChecker(intrinsics);
            float x = obj_fovChecker.getFov(imageSize.width, FovAxis::X);
            float y = obj_fovChecker.getFov(imageSize.height, FovAxis::Y);
            widget->lbl_FOVResults->setStyleSheet("color : blue ; font : 14pt ;");
            widget->lbl_FOVResults->setText(" Угол обзора : " + QString::number(x) + "  x  " + QString::number(y));
        }
    }
}

bool FieldOfViewWindow::openFolderWithIntrinsics(cv::Mat& matrix, cv::Mat& distortion, cv::Size& imgSize) {
    QString lineEdit_fileName = widget->le_filename->text();
    filename = folderPath.toStdString() + "/" + lineEdit_fileName.toStdString() + ".yml";
    if (!QFile::exists(QString::fromStdString(filename)) || getFileSize(filename.c_str()) == 0) {
        widget->lbl_FOVResults->setStyleSheet("color : red ; font : 14pt ;");
        widget->lbl_FOVResults->setText("Файл пуст!");
        return false;
    } else {
        try {
            cv::FileStorage fs(filename, CV_STORAGE_READ);
            if (fs.isOpened()) {
                fs["m"] >> matrix;
                fs["d"] >> distortion;
                fs["s"] >> imgSize;
                fs.release();
            }
        } catch (const std::exception& err) {
            widget->lbl_FOVResults->setStyleSheet("color : red ; font : 14pt ;");
            widget->lbl_FOVResults->setText("Невозможно считать данные из файла!");
            return false;
        }
    }
    return true;
}

std::ifstream::pos_type FieldOfViewWindow::getFileSize(const char* filename) {
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

FieldOfViewWindow::~FieldOfViewWindow() {
    delete widget;
}
