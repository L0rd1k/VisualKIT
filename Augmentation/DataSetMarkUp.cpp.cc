/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DataSetMarkUp.cpp
 * Author: Ilya Petrikov
 *
 * Created on March 16, 2020, 2:39 PM
 */

#include "DataSetMarkUp.h"

DataSetMarkUp::DataSetMarkUp() : widget(new Ui::DataSetMarkUp) {
    widget->setupUi(this);
    widget->lbl_image->installEventFilter(this);
    connect(widget->pb_importDataSet, SIGNAL(clicked(bool)), this, SLOT(regime_MarkUp()));
    connect(widget->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(selectDatasetImage(int, int)));
}

bool DataSetMarkUp::eventFilter(QObject *object, QEvent *event) {
    if (object == widget->lbl_image) {
        if (getMouseImageActivity(event)) {
            return true;
        }
    }
    return false;
}

bool DataSetMarkUp::getMouseImageActivity(QEvent * event) {
    switch (event->type()) {
        case QEvent::MouseButtonPress:
        {
            qDebug() << "Mouse pressed";
            return true;
        }
        case QEvent::MouseButtonRelease:
        {
            qDebug() << "Mouse released";
            return true;
        }
        case QEvent::MouseMove:
        {
            qDebug() << "Mouse mouse move";
            return true;
        }
        case QEvent::MouseButtonDblClick:
        {
            qDebug() << "Mouse double cliked";
            return true;
        }
        default:
            return false;
    }
}

void DataSetMarkUp::selectDatasetImage(int row, int) {

    QString imageValue = widget->tableWidget->item(row, 1)->text();
    setImage(folderPath + "/" + imageValue);
}

QStringList DataSetMarkUp::extractImagesFromFolder() {
    folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    QStringList imagesName;
    if (!folderPath.isEmpty()) {
        QDir directory(folderPath);
        QStringList imagesExtensions = {"*jpeg", "*jpg", "*png"};
        imagesName = directory.entryList(imagesExtensions, QDir::Filter::Files);
    }
    qDebug() << imagesName.size();

    return imagesName;
}

void DataSetMarkUp::regime_MarkUp() {
    dataSetImages = extractImagesFromFolder();
    if (!dataSetImages.isEmpty()) {
        dataSetView(dataSetImages);
    } else {

        std::cout << "OK" << std::endl;
    }
}

void DataSetMarkUp::setImage(QString imagePath) {
    _map.load(imagePath);
    if (_map.isNull()) {
    } else {

        _map.scaled(widget->lbl_image->size(), Qt::KeepAspectRatio);
        QPixmap resultPixmap(_map.size());
        QPainter p(&resultPixmap);
        p.drawPixmap(0, 0, QPixmap::fromImage(_map));
        widget->lbl_image->setPixmap(QPixmap::fromImage(_map).scaled(widget->lbl_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void DataSetMarkUp::dataSetView(QStringList dataSetImagesList) {
    QStringList tableHeader;
    tableHeader << "ID" << "Имя файла" << "Кол-во объектов" << "Класс";
    widget->tableWidget->setColumnCount(3);
    QHeaderView* header = widget->tableWidget->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);
    widget->tableWidget->setHorizontalHeaderLabels(tableHeader);
    widget->tableWidget->setRowCount(0);
    for (int id = 0; id < dataSetImagesList.size(); id++) {

        int currentRow = widget->tableWidget->rowCount();
        widget->tableWidget->setRowCount(currentRow + 1);
        widget->tableWidget->setItem(currentRow, 0, new QTableWidgetItem("Загрузка -> " + QString::number(id + 1)));
        widget->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(QString(dataSetImagesList[id])));
        widget->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(QString::number(0)));
    }
    widget->tableWidget->selectRow(0);
    QString imageValue = widget->tableWidget->item(widget->tableWidget->currentRow(), 1)->text();
    setImage(folderPath + "/" + imageValue);

}

DataSetMarkUp::~DataSetMarkUp() {
    delete widget;
}
