/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CameraCalibration.cpp
 * Author: ilya
 * 
 * Created on November 21, 2019, 11:39 AM
 */

#include "CameraCalibration.h"

CameraCalibration::CameraCalibration() {
}

QString CameraCalibration::getImagesFolder() {
    folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    return folderPath;
}

QStringList CameraCalibration::getImagesFromFolder(QString folderPath) {
    QDir dir(folderPath);
    files = dir.entryList(QStringList() << "*.jpg" << "*.jpeg" << "*.png", QDir::Files | QDir::NoDotAndDotDot);
    return files;
}

QString CameraCalibration::saveCalibrationResults(Mat m, Mat d, Size imageSize, double err) {
    std::string filename = folderPath.toStdString() + "/intrinsics.yml";
    FileStorage fs(filename, CV_STORAGE_WRITE);
    if (fs.isOpened()) {
        fs << "m" << m << "d" << d << "s" << imageSize << "err" << err;
        oss << endl << "Matrix = " << endl << m << endl << endl <<
                "Distortion = " << d << endl << endl <<
                "Image size = " << imageSize << endl << endl <<
                "Error = " << err << endl;
                fs.release();
    }
    return QString(oss.str().c_str());
}

std::tuple<double, cv::Mat, cv::Mat> CameraCalibration::collectCalibrationObjectPoints(PointsCollectorBase &obj_pointsCollector, vector< vector<Point2f> > imagesPoints, Size imageSize) {
    vector< vector<Point3f> > objectPoints;
    int samplesCounter = imagesPoints.size();
    for (int i = 0; i < samplesCounter; ++i) {
        objectPoints.push_back(obj_pointsCollector.collectObjectPoints());
    }
    Mat m, d;
    vector <Mat> r, t;
    double err = calibrateCamera(objectPoints, imagesPoints, imageSize, m, d, r, t,
            CV_CALIB_FIX_K5 |
            CV_CALIB_FIX_K6,
            TermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 100, 1e-5));
    return std::make_tuple(err, m, d);
}

CameraCalibration::~CameraCalibration() {
}



