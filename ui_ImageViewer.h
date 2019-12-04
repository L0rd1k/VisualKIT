/********************************************************************************
** Form generated from reading UI file 'ImageViewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_Name;
    QLabel *label_ImageName;
    QLabel *label_ImagePath;
    QHBoxLayout *horizontalLayout_Size;
    QLabel *label_ImageSize;
    QLabel *label_ImageSizeValue;
    QLabel *ImageLabel;
    QFrame *line;

    void setupUi(QWidget *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(596, 368);
        verticalLayout = new QVBoxLayout(ImageViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_Name = new QHBoxLayout();
        horizontalLayout_Name->setObjectName(QString::fromUtf8("horizontalLayout_Name"));
        label_ImageName = new QLabel(ImageViewer);
        label_ImageName->setObjectName(QString::fromUtf8("label_ImageName"));
        label_ImageName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_Name->addWidget(label_ImageName);

        label_ImagePath = new QLabel(ImageViewer);
        label_ImagePath->setObjectName(QString::fromUtf8("label_ImagePath"));

        horizontalLayout_Name->addWidget(label_ImagePath);


        verticalLayout->addLayout(horizontalLayout_Name);

        horizontalLayout_Size = new QHBoxLayout();
        horizontalLayout_Size->setObjectName(QString::fromUtf8("horizontalLayout_Size"));
        label_ImageSize = new QLabel(ImageViewer);
        label_ImageSize->setObjectName(QString::fromUtf8("label_ImageSize"));

        horizontalLayout_Size->addWidget(label_ImageSize);

        label_ImageSizeValue = new QLabel(ImageViewer);
        label_ImageSizeValue->setObjectName(QString::fromUtf8("label_ImageSizeValue"));

        horizontalLayout_Size->addWidget(label_ImageSizeValue);


        verticalLayout->addLayout(horizontalLayout_Size);

        ImageLabel = new QLabel(ImageViewer);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        ImageLabel->setMinimumSize(QSize(300, 300));
        ImageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ImageLabel);

        line = new QFrame(ImageViewer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QWidget *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "ImageViewer", 0, QApplication::UnicodeUTF8));
        label_ImageName->setText(QApplication::translate("ImageViewer", "Image Name:", 0, QApplication::UnicodeUTF8));
        label_ImagePath->setText(QString());
        label_ImageSize->setText(QApplication::translate("ImageViewer", "Image Size:", 0, QApplication::UnicodeUTF8));
        label_ImageSizeValue->setText(QString());
        ImageLabel->setText(QApplication::translate("ImageViewer", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
