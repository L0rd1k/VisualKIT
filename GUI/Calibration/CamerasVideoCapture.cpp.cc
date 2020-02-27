/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CamerasVideoCapture.cpp
 * Author: Ilya Petrikov
 *
 * Created on December 27, 2019, 1:20 PM
 */

#include <memory>
#include <qt4/QtGui/qcombobox.h>
#include "CamerasVideoCapture.h"

CamerasVideoCapture::CamerasVideoCapture()
: widget(new Ui::CamerasVideoCapture) {
    widget->setupUi(this);
    qRegisterMetaType< cv::Mat >("cv::Mat");
    connect(widget->btn_startStreaming, SIGNAL(clicked()), this, SLOT(getCameraFrame()));
    connect(widget->tb_AddPath, SIGNAL(clicked()), this, SLOT(addNewDevice()));
    setHeaderConfiguration();
    QVector<QString> iniConf = getIniCameraConfigurations();
    addVideoPathToComboBox(iniConf);
}

void CamerasVideoCapture::setHeaderConfiguration() {
    QStringList tableHeader;
    tableHeader << "Status" << "Path";
    widget->tableWidget->setColumnCount(4);
    widget->tableWidget->setShowGrid(true);
    widget->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

QVector<QString> CamerasVideoCapture::getIniCameraConfigurations() {
    settings = new QSettings("./Settings/camerasConfig.ini", QSettings::IniFormat);
    settings->beginGroup("Cameras_Paths");
    keys = settings->allKeys();
    for (auto &elem : keys)
        vec_values.push_back(settings->value(elem).toString());
    return vec_values;
}

void CamerasVideoCapture::addVideoPathToComboBox(QVector<QString> &iniConf) {
    widget->tableWidget->setRowCount(0);
    for (auto &item : iniConf) {
        int currentRow = widget->tableWidget->rowCount();
        widget->tableWidget->setRowCount(currentRow + 1);
        // --------------------- 1*
        iCheck = new QTableWidgetItem();
        iCheck->data(Qt::CheckStateRole);
        iCheck->setCheckState(Qt::Unchecked);
        iCheck->setText("False");
        widget->tableWidget->setItem(currentRow, 0, iCheck);
        // --------------------- 2*
        QComboBox* combo = new QComboBox();
        QStringList qlist{"Undefined", "Stream", "Video"};
        combo->addItems(qlist);
        widget->tableWidget->setCellWidget(currentRow, 1, (QWidget*) combo);
        // --------------------- 3*
        widget->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(item));
        // --------------------- 4*
        QPushButton *deleteButton = new QPushButton();
        deleteButton->setText(QString("Delete"));
        mapDelete.insert(currentRow, deleteButton);
        widget->tableWidget->setCellWidget(currentRow, 3, (QWidget*) deleteButton);
        connect(deleteButton, SIGNAL(clicked()), this, SLOT(removeDevice()));
    }
    qDebug() << "Map delete size : " << mapDelete.size();
}

void CamerasVideoCapture::addNewDevice() {
    if (!widget->le_Path->text().isEmpty()) {
        settings->setValue("Path" + QString::number(vec_values.size()), widget->le_Path->text());
        vec_values.push_back(widget->le_Path->text());
        widget->tableWidget->clear();
        settings->sync();
        addVideoPathToComboBox(vec_values);
    }
}

void CamerasVideoCapture::removeDevice() {
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    if (pButton && mapDelete.contains(mapDelete.key(pButton))) {
        int currentKey = mapDelete.key(pButton);
        // 1. Remove form vector
        vec_values.remove(currentKey);
        // 2. Remove from ini file
        mapDelete.remove(currentKey);
        settings->remove(QString("Path") + QString::number(currentKey));
        // 3. Сhange iteration in ini file
        for (auto i = currentKey + 1; i < vec_values.size() + 1; i++) {
            QString currentStr = QString(widget->tableWidget->item(i, 2)->text());
            mapDelete.remove(i);
            settings->remove(QString("Path") + QString::number(i));
            settings->setValue("Path" + QString::number(i - 1), currentStr);
        }
        addVideoPathToComboBox(vec_values);
    }
}

void CamerasVideoCapture::getCheckedCameras() {
    for (auto i = 0; i < widget->tableWidget->rowCount(); i++) {
        if (widget->tableWidget->item(i, 0)->checkState() == 2) {
            activePath.push_back(widget->tableWidget->item(i, 2)->text());
        }
    }
}

void CamerasVideoCapture::getCameraFrame() {
    getCheckedCameras();
    if (activePath.size() != 0) {
        for (auto i = 0; i < activePath.size(); i++) {
            CameraViewer *camView = new CameraViewer();
            QThread *currentThread = new QThread();
            threads.push_back(currentThread);
            CameraCapture *camCap = new CameraCapture(activePath[i]);
            camCap->moveToThread(currentThread);
            widget->horizontalLayout->addWidget(camView);
            connect(currentThread, SIGNAL(started()), camCap, SLOT(readVideo()));
            connect(currentThread, SIGNAL(finished()), currentThread, SLOT(deleteLater()));
            connect(camCap, SIGNAL(frameFinished(cv::Mat)), camView, SLOT(setFrame(cv::Mat)));
            connect(camCap, SIGNAL(finished()), currentThread, SLOT(quit()));
            connect(camCap, SIGNAL(finished()), camCap, SLOT(deleteLater()));
            currentThread->start();
            widget->lbl_InfoLabel->setStyleSheet("color : green ; font: 14pt;}");
            widget->lbl_InfoLabel->setText("Видеопоток запущен!");
        }
    } else {
        widget->lbl_InfoLabel->setStyleSheet("color : red ; font: 14pt;}");
        widget->lbl_InfoLabel->setText("Видеопоток не выбран!");
    }
}

CamerasVideoCapture::~CamerasVideoCapture() {
    delete iCheck;
    delete settings;
    delete widget;
}
