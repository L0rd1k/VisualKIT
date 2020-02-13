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

#include "CamerasVideoCapture.h"

CamerasVideoCapture::CamerasVideoCapture()
: widget(new Ui::CamerasVideoCapture) {
    widget->setupUi(this);

    connect(widget->btn_startStreaming, SIGNAL(clicked()), this, SLOT(getCameraFrame()));

    setHeaderConfiguration();
    addVideoPathToComboBox();
    //getCameraFrame();

}

void CamerasVideoCapture::setHeaderConfiguration() {
    QStringList tableHeader;
    tableHeader << "Status" << "Path";
    widget->tableWidget->setColumnCount(2);
    widget->tableWidget->setShowGrid(true);
    widget->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

QVector<QString> CamerasVideoCapture::getIniCameraConfigurations() {
    QVector<QString> vec_values;
    QSettings settings("./Settings/camerasConfig.ini", QSettings::IniFormat);
    settings.beginGroup("Cameras_Paths");
    QStringList keys = settings.allKeys();
    for (auto &elem : keys)
        vec_values.push_back(settings.value(elem).toString());
    return vec_values;
}

void CamerasVideoCapture::addVideoPathToComboBox() {
    widget->tableWidget->setRowCount(0);
    for (auto &item : getIniCameraConfigurations()) {
        int currentRow = widget->tableWidget->rowCount();
        widget->tableWidget->setRowCount(currentRow + 1);
        QTableWidgetItem *iCheck = new QTableWidgetItem();
        iCheck->data(Qt::CheckStateRole);
        iCheck->setCheckState(Qt::Unchecked);
        widget->tableWidget->setItem(currentRow, 0, iCheck);
        widget->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(item));
    }
}

void CamerasVideoCapture::getCameraFrame() {
    for (auto i = 0; i < widget->tableWidget->rowCount(); i++) {
        if (widget->tableWidget->item(i, 0)->checkState() == 2) {
            activePath.push_back(widget->tableWidget->item(i, 1)->text());
        }
    }
    
    
    
}

CamerasVideoCapture::~CamerasVideoCapture() {
}
