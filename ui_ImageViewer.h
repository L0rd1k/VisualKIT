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
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label_ImageSize;
    QLabel *label_ImagePath;
    QLabel *label_ImageName;
    QLabel *label_ImageSizeValue;
    QHBoxLayout *horizontalLayout;
    QLabel *ImageLabel;
    QToolButton *btn_OpenFullImage;
    QFrame *line;

    void setupUi(QWidget *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QString::fromUtf8("ImageViewer"));
        ImageViewer->resize(579, 425);
        ImageViewer->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(ImageViewer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_ImageSize = new QLabel(ImageViewer);
        label_ImageSize->setObjectName(QString::fromUtf8("label_ImageSize"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_ImageSize);

        label_ImagePath = new QLabel(ImageViewer);
        label_ImagePath->setObjectName(QString::fromUtf8("label_ImagePath"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_ImagePath);

        label_ImageName = new QLabel(ImageViewer);
        label_ImageName->setObjectName(QString::fromUtf8("label_ImageName"));
        label_ImageName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_ImageName);

        label_ImageSizeValue = new QLabel(ImageViewer);
        label_ImageSizeValue->setObjectName(QString::fromUtf8("label_ImageSizeValue"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_ImageSizeValue);


        verticalLayout->addLayout(formLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ImageLabel = new QLabel(ImageViewer);
        ImageLabel->setObjectName(QString::fromUtf8("ImageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageLabel->sizePolicy().hasHeightForWidth());
        ImageLabel->setSizePolicy(sizePolicy);
        ImageLabel->setMinimumSize(QSize(350, 300));
        ImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ImageLabel);


        verticalLayout->addLayout(horizontalLayout);

        btn_OpenFullImage = new QToolButton(ImageViewer);
        btn_OpenFullImage->setObjectName(QString::fromUtf8("btn_OpenFullImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(20);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(btn_OpenFullImage->sizePolicy().hasHeightForWidth());
        btn_OpenFullImage->setSizePolicy(sizePolicy1);
        btn_OpenFullImage->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(btn_OpenFullImage);

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
        label_ImageSize->setText(QApplication::translate("ImageViewer", "Image Size:", 0, QApplication::UnicodeUTF8));
        label_ImagePath->setText(QString());
        label_ImageName->setText(QApplication::translate("ImageViewer", "Image Name:", 0, QApplication::UnicodeUTF8));
        label_ImageSizeValue->setText(QString());
        ImageLabel->setText(QApplication::translate("ImageViewer", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_OpenFullImage->setText(QApplication::translate("ImageViewer", "Full Image Size", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
