/* 
 * File:   CalibrationExecutor.h
 * Author: ilya petrikov
 *
 * Created on November 22, 2019, 5:23 PM
 */

#ifndef _CALIBRATIONEXECUTOR_H
#define _CALIBRATIONEXECUTOR_H

#include "ui_CalibrationExecutor.h"
#include "Cameras/CameraViewer.h"
#include "Cameras/ImageViewer.h"
#include "Utils/FieldOfViewChecker.h"
#include "Utils/Calibration/PointsCollectorBase.h"
#include "Utils/Calibration/PointsCollectorChess.h"
#include "Utils/Calibration/PointsCollectorCircles.h"
#include "Utils/Calibration/CameraCalibration.h"

#include <string>
#include <iostream>
#include <utility>
#include <memory>

#ifndef QT_INCUDE
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QLabel>
#include <QElapsedTimer>
#include <QPainter> 
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QDesktopServices>
#include <QLayoutItem>
#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>
#endif

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#endif

struct PatternConfig {
public:
    int calib_horizontal_val;
    int calib_vertical_val;
    double calib_size_val;
public:
    PatternConfig(int chv, int cvv, double csv) :
    calib_horizontal_val(chv),
    calib_vertical_val(cvv),
    calib_size_val(csv) {
    }
};

class CalibrationExecutor : public QWidget {
    Q_OBJECT
public:
    CalibrationExecutor();
    virtual ~CalibrationExecutor();
    void openFolderWithIntrinsics(cv::Mat& m, cv::Mat& d, cv::Size& s);
    int calculateFoV();
    int calibrate();
private slots:
    void calculateFieldOfView();
    void camerasCalibration();
    void selectCheckboxChessboard();
    void selectCheckboxCircle();
    void collectImagesFromSingleCamera();
    void updateFrame();
signals:
    void imageReady(cv::Mat);
private:
    Ui::CalibrationExecutor *widget = NULL;
    std::unique_ptr<PointsCollectorBase> obj_pointsCollector;
    CameraCalibration* obj_cameraCalibration;
    std::vector<CameraViewer*> viewers;
private:
    CameraViewer *obj_camViewer;
    cv::VideoCapture capture;
    PatternConfig *patternConf;
    int counterImageFound = 0;
    QString folderPath;
    QStringList imagesFromFolder;
    vector< vector<Point2f> > imagesPoints;
    Size imageSize;
    int calib_horizontal_val = 0;
    int calib_vertical_val = 0;
    double calib_size_val = 0.0;
    std::string filename;
    std::tuple<double, cv::Mat, cv::Mat> calibrationError;
    QTimer *timer;
private:
    QVector<QString> getIniCameraConfigurations();
    void addVideoPathToComboBox();
    cv::Mat collectTemplatePoints(cv::Mat &originalImage);
    cv::Mat showTemplatePoints(cv::Mat &image, vector<Point2f>& corners);
    void singleCameraCalibration();
    void setDefaultCircleValue();
    void setDefaultChessboardValue();
    void removeAllElementsFromLayout(QLayout* layout);
    void checkCurrentTemplateState();
    void setDefaultSettings();
};

#endif /* _CALIBRATIONEXECUTOR_H */
