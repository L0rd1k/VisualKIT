/********************************************************************************
** Form generated from reading UI file 'CameraViewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAVIEWER_H
#define UI_CAMERAVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraViewer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *ImageLabel;

    void setupUi(QWidget *CameraViewer)
    {
        if (CameraViewer->objectName().isEmpty())
            CameraViewer->setObjectName(QString::fromUtf8("CameraViewer"));
        CameraViewer->resize(572, 396);
        verticalLayout = new QVBoxLayout(CameraViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ImageLabel = new QLabel(CameraViewer);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setMinimumSize(QSize(300, 300));
        ImageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ImageLabel);


        retranslateUi(CameraViewer);

        QMetaObject::connectSlotsByName(CameraViewer);
    } // setupUi

    void retranslateUi(QWidget *CameraViewer)
    {
        CameraViewer->setWindowTitle(QApplication::translate("CameraViewer", "CameraViewer", 0, QApplication::UnicodeUTF8));
        ImageLabel->setText(QApplication::translate("CameraViewer", "VideoStream", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraViewer: public Ui_CameraViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAVIEWER_H
