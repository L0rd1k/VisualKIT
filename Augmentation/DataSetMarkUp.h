/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataSetMarkUp.h
 * Author: Ilya Petrikov
 *
 * Created on March 16, 2020, 2:39 PM
 */

#ifndef _DATASETMARKUP_H
#define _DATASETMARKUP_H

#include "ui_DataSetMarkUp.h"

#include "QtCore"
#include "QFileDialog"
#include "QPainter"
#include "QGraphicsScene"
#include "QKeyEvent"

#include <iostream>

class DataSetMarkUp : public QWidget {
    Q_OBJECT
public:
    DataSetMarkUp();
    virtual ~DataSetMarkUp();
protected:
    bool eventFilter(QObject *object, QEvent *event) override; 
    bool getMouseImageActivity(QEvent *event);
private:
    Ui::DataSetMarkUp *widget;
    QString folderPath;
    QStringList dataSetImages;
    QImage _map;
private:
    QStringList extractImagesFromFolder();
    void dataSetView(QStringList dataSetImagesList);
    void setImage(QString imagePath);
private slots:
    void regime_MarkUp();
    void selectDatasetImage(int row, int column);
};

#endif /* _DATASETMARKUP_H */
