/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SingleCameraCalibration.cpp
 * Author: Ilya Petrikov
 * Created on December 20, 2019, 2:01 PM
 */

#include "SingleCameraCalibration.h"

SingleCameraCalibration::SingleCameraCalibration() : widget(new Ui::SingleCameraCalibration) {
    widget->setupUi(this);
    connect(widget->checkBox_Chessboard, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxCircle()));
    connect(widget->checkBox_Circle, SIGNAL(clicked(bool)), this, SLOT(selectCheckboxChessboard()));
    connect(widget->btn_calculateCalibrationClicked, SIGNAL(clicked(bool)), this, SLOT(cameraCalibration()));
    setDefaultCircleValue();
}

void SingleCameraCalibration::setDefaultCircleValue() {
    widget->spinBox_HorizontalValue->setValue(11);
    widget->spinBox_VerticalValue->setValue(4);
    widget->doubleSpinBox_SizeValue->setValue(45.5);
}

void SingleCameraCalibration::setDefaultChessboardValue() {
    widget->spinBox_HorizontalValue->setValue(6);
    widget->spinBox_VerticalValue->setValue(8);
    widget->doubleSpinBox_SizeValue->setValue(80);
}

void SingleCameraCalibration::selectCheckboxCircle() {
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

void SingleCameraCalibration::selectCheckboxChessboard() {
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

SingleCameraCalibration::~SingleCameraCalibration() {
    delete patternConf;
    delete widget;
}

void SingleCameraCalibration::checkCurrentPatternToUse() {
    patternConf = new PatternConfig(
            widget->spinBox_HorizontalValue->value(),
            widget->spinBox_VerticalValue->value(),
            widget->doubleSpinBox_SizeValue->value());
    if (widget->checkBox_Circle->checkState() == Qt::Checked) {
        obj_pointsCollector = std::make_unique<PointsCollectorCircles>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
    }
    if (widget->checkBox_Chessboard->checkState() == Qt::Checked) {
        obj_pointsCollector = std::make_unique<PointsCollectorChess>(patternConf->calib_vertical_val, patternConf->calib_horizontal_val, patternConf->calib_size_val);
    }
}

void SingleCameraCalibration::calibrationTableInfo(int id, int currentRow, QString status) {
    widget->tableWidget->setItem(currentRow, 0, new QTableWidgetItem("Загрузка -> " + QString::number(id + 1)));
    widget->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString(imagesFromFolder[id])));
    widget->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(status));
}

void SingleCameraCalibration::calibrationTableHeader() {
    tableHeader << "ID" << "Имя файла" << "Статус";
    widget->tableWidget->setColumnCount(3);
    QHeaderView* header = widget->tableWidget->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);
    widget->tableWidget->setHorizontalHeaderLabels(tableHeader);
}

void SingleCameraCalibration::cameraCalibration() {
    widget->tableWidget->setRowCount(0);
    removeAllElementsFromLayout(widget->vl_Cameras);
    widget->label_HintResults->setText("");
    clearLabels();
    obj_cameraCalibration = new CameraCalibration();
    checkCurrentPatternToUse();
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
                    widget->vl_Cameras->addWidget(obj_imageViewer, 50);
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
        obj_cameraCalibration->saveCalibrationResults(std::get<1>(calibrationError), std::get<2>(calibrationError), imageSize, std::get<0>(calibrationError));
        widget->le_error->setText(QString::number(std::get<0>(calibrationError)));
        widget->le_size->setText(QString::number(imageSize.width) + " X " + QString::number(imageSize.height));
        widget->le_focalLengthX->setText(QString::number(std::get<1>(calibrationError).at<double>(0, 0)));
        widget->le_focalLengthY->setText(QString::number(std::get<1>(calibrationError).at<double>(1, 1)));
        widget->le_princPointX->setText(QString::number(std::get<1>(calibrationError).at<double>(0, 2)));
        widget->le_princPointY->setText(QString::number(std::get<1>(calibrationError).at<double>(1, 2)));
        widget->le_K1->setText(QString::number(std::get<2>(calibrationError).at<double>(0, 0)));
        widget->le_K2->setText(QString::number(std::get<2>(calibrationError).at<double>(0, 1)));
        widget->le_K3->setText(QString::number(std::get<2>(calibrationError).at<double>(0, 2)));
        widget->le_K4->setText(QString::number(std::get<2>(calibrationError).at<double>(0, 3)));
        widget->le_K5->setText(QString::number(std::get<2>(calibrationError).at<double>(0, 4)));
    }
}

void SingleCameraCalibration::clearLabels() {
    widget->label_HintResults->setText("");
    widget->le_error->setText("");
    widget->le_size->setText("");
    widget->le_focalLengthX->setText("");
    widget->le_focalLengthY->setText("");
    widget->le_princPointX->setText("");
    widget->le_princPointY->setText("");
    widget->le_K1->setText("");
    widget->le_K2->setText("");
    widget->le_K3->setText("");
    widget->le_K4->setText("");
    widget->le_K5->setText("");
}

void SingleCameraCalibration::removeAllElementsFromLayout(QLayout* layout) {
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
