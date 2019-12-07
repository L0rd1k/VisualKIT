/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CalibrationExecutor.cpp
 * Author: ilya
 * Created on November 22, 2019, 5:23 PM
 */

#include <qt4/QtCore/qfsfileengine.h>
#include "CalibrationExecutor.h"
#include "ui_MainMenuWindow.h"

CalibrationExecutor::CalibrationExecutor() : widget(new Ui::CalibrationExecutor) {
    widget->setupUi(this);
    connect(widget->btn_calculateFOVClicked, SIGNAL(clicked(bool)), this, SLOT(calculateFieldOfView()));
    connect(widget->btn_calculateCalibrationClicked, SIGNAL(clicked(bool)), this, SLOT(camerasCalibration()));
    connect(widget->checkBox_Chessboard, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxCircle()));
    connect(widget->checkBox_Circle, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxChessboard()));
    widget->lineEdit_IntrinsicsFileName->setText("intrinsics");
    setDefaultCircleValue();
    singleCameraCalibration();
    widget->scrollArea->setVisible(false);
}
// ---> DESIGN CHECKER - BEGIN

void CalibrationExecutor::setDefaultCircleValue() {
    widget->spinBox_HorizontalValue->setValue(11);
    widget->spinBox_VerticalValue->setValue(4);
    widget->doubleSpinBox_SizeValue->setValue(45.5);
}

void CalibrationExecutor::setDefaultChessboardValue() {
    widget->spinBox_HorizontalValue->setValue(6);
    widget->spinBox_VerticalValue->setValue(8);
    widget->doubleSpinBox_SizeValue->setValue(80);
}

void CalibrationExecutor::selectCheckboxCircle() {
    if (widget->checkBox_Circle->checkState() == Qt::Checked) {
        setDefaultChessboardValue();
        widget->checkBox_Chessboard->setChecked(true);
        widget->checkBox_Circle->setChecked(false);
    } else {
        setDefaultCircleValue();
        widget->checkBox_Chessboard->setChecked(false);
        widget->checkBox_Circle->setChecked(true);
    }
}

void CalibrationExecutor::selectCheckboxChessboard() {
    if (widget->checkBox_Chessboard->checkState() == Qt::Checked) {
        setDefaultCircleValue();
        widget->checkBox_Chessboard->setChecked(false);
        widget->checkBox_Circle->setChecked(true);
    } else {
        setDefaultChessboardValue();
        widget->checkBox_Chessboard->setChecked(true);
        widget->checkBox_Circle->setChecked(false);
    }
}

void CalibrationExecutor::removeAllElementsFromLayout(QLayout* layout) {
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
// ---> DESIGN CHECKER - END


// ---> VIDEO IMAGES EXTRACTION - BEGIN

QVector<QString> CalibrationExecutor::getIniCameraConfigurations() {
    QVector<QString> vec_values;
    QSettings settings("./Settings/camerasConfig.ini", QSettings::IniFormat);
    settings.beginGroup("Cameras_Paths");
    QStringList keys = settings.allKeys();
    for (int i = 0; i < keys.size(); i++) {
        QString value = settings.value(keys[i]).toString();
        vec_values.push_back(value);
    }
    return vec_values;
}

void CalibrationExecutor::addVideoPathToComboBox() {
    QVector<QString> pathIniValues = getIniCameraConfigurations();
    for (int itr = 0; itr < pathIniValues.size(); itr++) {
        widget->comboBox_pathOptions->addItem(pathIniValues[itr]);
    }
}

void CalibrationExecutor::singleCameraCalibration() {
    addVideoPathToComboBox();
    connect(widget->btn_startStreaming, SIGNAL(clicked(bool)), this, SLOT(collectImagesFromSingleCamera()));
}

void CalibrationExecutor::updateFrame() {
    cv::Mat frame;
    capture >> frame;
    cv::cvtColor(frame, frame, CV_BGR2RGB);
    if (widget->checkBox_RealTime->isChecked()) {
        collectTemplatePoints(frame);
    }
    connect(this, SIGNAL(imageReady(cv::Mat)), obj_camViewer, SLOT(setFrame(cv::Mat)));
    emit obj_camViewer->setFrame(collectTemplatePoints(frame));
}

void CalibrationExecutor::collectImagesFromSingleCamera() {
    std::string videoPath;
    if (!widget->lineEdit_videoIPPath->text().isEmpty()) {
        videoPath = widget->lineEdit_videoIPPath->text().toStdString();
    } else {
        videoPath = widget->comboBox_pathOptions->currentText().toStdString();
    }
    obj_camViewer = new CameraViewer(videoPath);
    capture = obj_camViewer->startCapturing();
    if (!capture.isOpened()) {
        widget->label_HintResults->setStyleSheet("color : red ; font: 14pt;}");
        widget->label_HintResults->setText("Захват потока не удался\n(проверьте правильность пути)!");
        return;
    }
    widget->scrollArea->setVisible(true);
    widget->verticalLayout_Cameras->addWidget(obj_camViewer, 50);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateFrame()));
    timer->start(20);
}

cv::Mat CalibrationExecutor::collectTemplatePoints(cv::Mat &originalImage) {
    obj_pointsCollector = std::make_unique<PointsCollectorChess>(8, 6, 27);
    auto points = obj_pointsCollector->collectFramePoints(originalImage);
    if (points.size() > 0) {
        cv::Mat resultImage = showTemplatePoints(originalImage, points);
        return resultImage;
    }
    return originalImage;
}

cv::Mat CalibrationExecutor::showTemplatePoints(cv::Mat &image, vector<Point2f> &corners) {
    if (image.cols > 0 && image.rows > 0 && corners.size() > 0) {
        Mat cornersImage = image.clone();
        drawChessboardCorners(cornersImage, obj_pointsCollector->getChessboardSize(), corners, true);
        return cornersImage;
    }
    return image;
}
// ---> VIDEO IMAGES EXTRACTION - END


// ---> IMAGES CALIBRATION - BEGIN

void CalibrationExecutor::checkCurrentTemplateState() {
    patternConf = new PatternConfig(widget->spinBox_HorizontalValue->value(),
            widget->spinBox_VerticalValue->value(),
            widget->doubleSpinBox_SizeValue->value());
    if (widget->checkBox_Circle->checkState() == Qt::Checked) {
        obj_pointsCollector = std::make_unique<PointsCollectorCircles>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
    }
    if (widget->checkBox_Chessboard->checkState() == Qt::Checked) {
        obj_pointsCollector = std::make_unique<PointsCollectorChess>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
    }
}

void CalibrationExecutor::camerasCalibration() {
    widget->scrollArea->setVisible(true);
    obj_cameraCalibration = new CameraCalibration();
    widget->listWidget->clear();
    removeAllElementsFromLayout(widget->verticalLayout_Cameras);
    checkCurrentTemplateState();
    folderPath = obj_cameraCalibration->getImagesFolder();
    imagesFromFolder = obj_cameraCalibration->getImagesFromFolder(folderPath);
    imagesPoints.clear();

    if (imagesFromFolder.size() == 0) {
        widget->label_HintResults->setStyleSheet("color : red ; font: 14pt;}");
        return;
    }
    
    for (int id = 0; id < imagesFromFolder.size(); id++) {
        ImageViewer* obj_imageViewer = new ImageViewer();
        Mat image = imread(folderPath.toStdString() + "/" + imagesFromFolder[id].toStdString());
        if (widget->comboBox_CameraBreed->currentIndex() == 1) {
            bitwise_not(image, image);
        }
        if (image.size().width == 0 || image.size().height == 0) {
            widget->listWidget->addItem(QString::number(id + 1) + " - Загрузка " + QString(imagesFromFolder[id]) + " <<  Точки не обнаружены!");
            continue;
        } else {
            imageSize = image.size();
            auto points = obj_pointsCollector->collectFramePoints(image);
            if (points.size() > 0) {
                counterImageFound++;
                widget->listWidget->addItem(QString::number(id + 1) + " - Загрузка " + QString(imagesFromFolder[id]));
                if (image.cols > 0 && image.rows > 0 && points.size() > 0) {
                    widget->verticalLayout_Cameras->addWidget(obj_imageViewer, 50);
                    drawChessboardCorners(image, obj_pointsCollector->getChessboardSize(), points, true);
                    cv::Mat imageWithCorners = image.clone();
                    obj_imageViewer->setFrame(imageWithCorners, QString(imagesFromFolder[id]));
                    imagesPoints.push_back(points);
                }
            } else {
                widget->listWidget->addItem(QString::number(id + 1) + " - Загрузка " + QString(imagesFromFolder[id]) + " <<  Точки не обнаружены!");
            }
        }
    }
    if (imagesPoints.size() == 0) {
        widget->label_HintResults->setStyleSheet("color : red ; font: 14pt;}");
        widget->label_HintResults->setText("Шаблон не был найден!");
    } else {
        widget->label_HintResults->setStyleSheet("color : green ; font: 14pt;}");
        widget->label_HintResults->setText("Шаблон был найден : " + QString::number(counterImageFound) + "/" + QString::number(imagesFromFolder.size()));
        counterImageFound = 0;
        calibrationError = obj_cameraCalibration->collectCalibrationObjectPoints(*obj_pointsCollector, imagesPoints, imageSize);
        widget->listWidget->addItem(obj_cameraCalibration->saveCalibrationResults(std::get<1>(calibrationError), std::get<2>(calibrationError), imageSize, std::get<0>(calibrationError)));
        widget->listWidget->addItem("Результаты калибровки : " + QString::number(std::get<0>(calibrationError)) + "\n");
    }
}
// ---> IMAGES CALIBRATION - END

// ---> FIELD OF VIEW - BEGIN

void CalibrationExecutor::calculateFieldOfView() {
    folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    if (!folderPath.isEmpty()) {
        calculateFoV();
    }
}

void CalibrationExecutor::openFolderWithIntrinsics(cv::Mat& matrix, cv::Mat& distortion, cv::Size & imgSize) {
    QString lineEdit_fileName = widget->lineEdit_IntrinsicsFileName->text();
    filename = folderPath.toStdString() + "/" + lineEdit_fileName.toStdString() + ".yml";
    cv::FileStorage fs(filename, CV_STORAGE_READ);
    if (fs.isOpened()) {
        fs["m"] >> matrix;
        fs["d"] >> distortion;
        fs["s"] >> imgSize;
        fs.release();
    }
}

int CalibrationExecutor::calculateFoV() {
    cv::Mat matrix, distortion;
    cv::Size imageSize;
    openFolderWithIntrinsics(matrix, distortion, imageSize);
    FieldOfViewChecker fovChecker(matrix);
    double x = fovChecker.getFov(imageSize.width, FovAxis::X);
    double y = fovChecker.getFov(imageSize.height, FovAxis::Y);
    widget->label_FOV->setStyleSheet("color : blue ; font: 14pt;}");
    widget->label_FOV->setText(" Угол обзора : " + QString::number(x) + "  x  " + QString::number(y));
    return 0;
}
// ---> FIELD OF VIEW - END

CalibrationExecutor::~CalibrationExecutor() {
    delete widget;
    delete obj_cameraCalibration;
    delete patternConf;
    delete timer;
}
