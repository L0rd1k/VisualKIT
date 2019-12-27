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
#include "ui_CalibrationExecutor.h"

CalibrationExecutor::CalibrationExecutor() : widget(new Ui::CalibrationExecutor) {
    widget->setupUi(this);
    connect(widget->btn_calculateCalibrationClicked, SIGNAL(clicked(bool)), this, SLOT(camerasCalibration()));
    connect(widget->checkBox_Chessboard, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxCircle()));
    connect(widget->checkBox_Circle, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxChessboard()));
    connect(widget->toolButton_ScreenShot, SIGNAL(clicked(bool)), this, SLOT(takeSnapShootFromVideo()));
    setDefaultCircleValue();
    singleCameraCalibration();
    widget->scrollArea->setVisible(false);
    timer = new QTimer(this);
    
    FieldOfViewWindow *fow = new FieldOfViewWindow();
    widget->verticalLayout_CalculateCalibration->addWidget(fow, 50);
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

void CalibrationExecutor::takeSnapShootFromVideo() {
    cv::Mat snapshoot = execFrame().clone();
    if (!QDir("./Snapshoot").exists()) {
        QDir().mkdir("./Snapshoot");
    }
    if (snapshoot.size() != Size(0, 0)) {
        counterImageSnapshoot++;
        QDateTime current = QDateTime::currentDateTime();
        imwrite("./Snapshoot/" + current.toString().toStdString() + ".jpg", snapshoot);
        widget->listWidget->addItem(QString::number(counterImageSnapshoot) + ") Скриншот " + current.toString() + " сохранен!");
    }
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

cv::Mat CalibrationExecutor::execFrame() {
    cv::Mat frame;
    capture >> frame;
    return frame;
}

void CalibrationExecutor::updateFrame() {
    cv::Mat frame = execFrame().clone();
    cv::cvtColor(frame, frame, CV_BGR2RGB);
    if (widget->checkBox_RealTime->isChecked()) {
        collectTemplatePoints(frame);
    }
    connect(this, SIGNAL(imageReady(cv::Mat)), obj_camViewer, SLOT(setFrame(cv::Mat)));
    emit obj_camViewer->setFrame(collectTemplatePoints(frame));
}

void CalibrationExecutor::collectImagesFromSingleCamera() {
    capture.release();
    timer->stop();
    
    removeAllElementsFromLayout(widget->verticalLayout_Cameras);
    std::string videoPath;
    if (!widget->lineEdit_videoIPPath->text().isEmpty()) {
        videoPath = widget->lineEdit_videoIPPath->text().toStdString();
    } else {
        videoPath = widget->comboBox_pathOptions->currentText().toStdString();
    }
//    obj_camViewer = new CameraViewer(videoPath);
    qDebug() << QString::fromStdString(videoPath);
    if (videoPath == "0") {
        capture.open(0);
    } else {
        capture.open(videoPath);
    }
//    capture = obj_camViewer->startCapturing();
    
    
    if (!capture.isOpened()) {
        widget->label_HintResults->setStyleSheet("color : red ; font: 14pt;}");
        widget->label_HintResults->setText("Захват потока не удался\n(проверьте правильность пути)!");
        return;
    }
    widget->scrollArea->setVisible(true);
    widget->verticalLayout_Cameras->addWidget(obj_camViewer, 50);
    //    timer = new QTimer(this);
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

//void CalibrationExecutor::checkCurrentTemplateState() {
//    patternConf = new PatternConfig(widget->spinBox_HorizontalValue->value(),
//            widget->spinBox_VerticalValue->value(),
//            widget->doubleSpinBox_SizeValue->value());
//    if (widget->checkBox_Circle->checkState() == Qt::Checked) {
//        obj_pointsCollector = std::make_unique<PointsCollectorCircles>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
//    }
//    if (widget->checkBox_Chessboard->checkState() == Qt::Checked) {
//        obj_pointsCollector = std::make_unique<PointsCollectorChess>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
//    }
//}

void CalibrationExecutor::calibrationTableInfo(int id, int currentRow, QString status) {
    widget->tableWidget->setItem(currentRow, 0, new QTableWidgetItem("Загрузка -> " + QString::number(id + 1)));
    widget->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString(imagesFromFolder[id])));
    widget->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(status));
}

void CalibrationExecutor::calibrationTableHeader() {
    tableHeader << "ID" << "Имя файла" << "Статус";
    widget->tableWidget->setColumnCount(3);
    QHeaderView* header = widget->tableWidget->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);
    widget->tableWidget->setHorizontalHeaderLabels(tableHeader);
}

void CalibrationExecutor::camerasCalibration() {
    timer->stop();



    widget->tableWidget->setRowCount(0);
    widget->scrollArea->setVisible(true);
    obj_cameraCalibration = new CameraCalibration();
    widget->listWidget->clear();
    removeAllElementsFromLayout(widget->verticalLayout_Cameras);
//    checkCurrentTemplateState();
    folderPath = obj_cameraCalibration->getImagesFolder();
    imagesFromFolder = obj_cameraCalibration->getImagesFromFolder(folderPath);
    imagesPoints.clear();

    if (imagesFromFolder.size() == 0) {
        widget->label_HintResults->setStyleSheet("color : red ; font: 14pt;}");
        return;
    } else {
        calibrationTableHeader();
    }
    for (int id = 0; id < imagesFromFolder.size(); id++) {
        ImageViewer* obj_imageViewer = new ImageViewer();
        int currentRow = widget->tableWidget->rowCount();
        widget->tableWidget->setRowCount(currentRow + 1);
        Mat image = imread(folderPath.toStdString() + "/" + imagesFromFolder[id].toStdString());
        if (widget->comboBox_CameraBreed->currentIndex() == 1) {
            bitwise_not(image, image);
        }
        if (image.size().width == 0 || image.size().height == 0) {
            calibrationTableInfo(id, currentRow, QString("Точки не обнаружены!"));
            widget->tableWidget->item(currentRow, 2)->setBackground(Qt::red);
            continue;
        } else {
            imageSize = image.size();
            auto points = obj_pointsCollector->collectFramePoints(image);
            if (points.size() > 0) {
                counterImageFound++;
                calibrationTableInfo(id, currentRow, QString("Точки найдены!"));
                widget->tableWidget->item(currentRow, 2)->setBackground(Qt::green);
                if (image.cols > 0 && image.rows > 0 && points.size() > 0) {
                    widget->verticalLayout_Cameras->addWidget(obj_imageViewer, 50);
                    drawChessboardCorners(image, obj_pointsCollector->getChessboardSize(), points, true);
                    cv::Mat imageWithCorners = image.clone();
                    obj_imageViewer->setFrame(imageWithCorners, QString(imagesFromFolder[id]));
                    imagesPoints.push_back(points);
                }
            } else {
                calibrationTableInfo(id, currentRow, QString("Точки не обнаружены!"));
                widget->tableWidget->item(currentRow, 2)->setBackground(Qt::red);
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
//        widget->listWidget->addItem(obj_cameraCalibration->saveCalibrationResults(std::get<1>(calibrationError), std::get<2>(calibrationError), imageSize, std::get<0>(calibrationError)));
        widget->listWidget->addItem("Результаты калибровки : " + QString::number(std::get<0>(calibrationError)) + "\n");
    }
}
// ---> IMAGES CALIBRATION - END

CalibrationExecutor::~CalibrationExecutor() {
    delete widget;
    delete obj_cameraCalibration;
//    delete patternConf;
    delete timer;
}
