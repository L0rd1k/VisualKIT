/********************************************************************************
** Form generated from reading UI file 'SingleCameraCalibration.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLECAMERACALIBRATION_H
#define UI_SINGLECAMERACALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleCameraCalibration
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *vl_calculateCalibration;
    QGroupBox *gb_calibrationPattern;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *hl_1;
    QCheckBox *checkBox_Circle;
    QCheckBox *checkBox_Chessboard;
    QHBoxLayout *hl_2;
    QComboBox *comboBox_CameraBreed;
    QHBoxLayout *hl_3;
    QLabel *labelVerticalValue;
    QSpinBox *spinBox_VerticalValue;
    QHBoxLayout *hl_4;
    QLabel *label_HorizontalValue;
    QSpinBox *spinBox_HorizontalValue;
    QHBoxLayout *hl_5;
    QLabel *label_SizeValue;
    QDoubleSpinBox *doubleSpinBox_SizeValue;
    QLabel *label_HintResults;
    QPushButton *btn_calculateCalibrationClicked;
    QTableWidget *tableWidget;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vl_Cameras;
    QHBoxLayout *hl_calibrationResults;
    QGridLayout *gl_calibrationResults;
    QGroupBox *gb_intrinsics;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *le_focalLengthX;
    QLineEdit *le_focalLengthY;
    QLineEdit *le_princPointX;
    QLineEdit *le_princPointY;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *gb_distortion;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *le_K1;
    QLineEdit *le_K2;
    QLineEdit *le_K3;
    QLineEdit *le_K4;
    QLineEdit *le_K5;
    QGroupBox *groupBox;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLineEdit *le_error;
    QLineEdit *le_size;
    QLabel *label_11;

    void setupUi(QWidget *SingleCameraCalibration)
    {
        if (SingleCameraCalibration->objectName().isEmpty())
            SingleCameraCalibration->setObjectName(QString::fromUtf8("SingleCameraCalibration"));
        SingleCameraCalibration->resize(844, 838);
        horizontalLayout = new QHBoxLayout(SingleCameraCalibration);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        vl_calculateCalibration = new QVBoxLayout();
        vl_calculateCalibration->setObjectName(QString::fromUtf8("vl_calculateCalibration"));
        gb_calibrationPattern = new QGroupBox(SingleCameraCalibration);
        gb_calibrationPattern->setObjectName(QString::fromUtf8("gb_calibrationPattern"));
        verticalLayout_5 = new QVBoxLayout(gb_calibrationPattern);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        hl_1 = new QHBoxLayout();
        hl_1->setObjectName(QString::fromUtf8("hl_1"));
        checkBox_Circle = new QCheckBox(gb_calibrationPattern);
        checkBox_Circle->setObjectName(QString::fromUtf8("checkBox_Circle"));
        checkBox_Circle->setChecked(true);

        hl_1->addWidget(checkBox_Circle);

        checkBox_Chessboard = new QCheckBox(gb_calibrationPattern);
        checkBox_Chessboard->setObjectName(QString::fromUtf8("checkBox_Chessboard"));

        hl_1->addWidget(checkBox_Chessboard);


        verticalLayout_5->addLayout(hl_1);

        hl_2 = new QHBoxLayout();
        hl_2->setObjectName(QString::fromUtf8("hl_2"));
        comboBox_CameraBreed = new QComboBox(gb_calibrationPattern);
        comboBox_CameraBreed->setObjectName(QString::fromUtf8("comboBox_CameraBreed"));

        hl_2->addWidget(comboBox_CameraBreed);


        verticalLayout_5->addLayout(hl_2);

        hl_3 = new QHBoxLayout();
        hl_3->setObjectName(QString::fromUtf8("hl_3"));
        labelVerticalValue = new QLabel(gb_calibrationPattern);
        labelVerticalValue->setObjectName(QString::fromUtf8("labelVerticalValue"));
        labelVerticalValue->setAlignment(Qt::AlignCenter);

        hl_3->addWidget(labelVerticalValue);

        spinBox_VerticalValue = new QSpinBox(gb_calibrationPattern);
        spinBox_VerticalValue->setObjectName(QString::fromUtf8("spinBox_VerticalValue"));

        hl_3->addWidget(spinBox_VerticalValue);


        verticalLayout_5->addLayout(hl_3);

        hl_4 = new QHBoxLayout();
        hl_4->setObjectName(QString::fromUtf8("hl_4"));
        label_HorizontalValue = new QLabel(gb_calibrationPattern);
        label_HorizontalValue->setObjectName(QString::fromUtf8("label_HorizontalValue"));
        label_HorizontalValue->setAlignment(Qt::AlignCenter);

        hl_4->addWidget(label_HorizontalValue);

        spinBox_HorizontalValue = new QSpinBox(gb_calibrationPattern);
        spinBox_HorizontalValue->setObjectName(QString::fromUtf8("spinBox_HorizontalValue"));

        hl_4->addWidget(spinBox_HorizontalValue);


        verticalLayout_5->addLayout(hl_4);

        hl_5 = new QHBoxLayout();
        hl_5->setObjectName(QString::fromUtf8("hl_5"));
        label_SizeValue = new QLabel(gb_calibrationPattern);
        label_SizeValue->setObjectName(QString::fromUtf8("label_SizeValue"));
        label_SizeValue->setAlignment(Qt::AlignCenter);

        hl_5->addWidget(label_SizeValue);

        doubleSpinBox_SizeValue = new QDoubleSpinBox(gb_calibrationPattern);
        doubleSpinBox_SizeValue->setObjectName(QString::fromUtf8("doubleSpinBox_SizeValue"));

        hl_5->addWidget(doubleSpinBox_SizeValue);


        verticalLayout_5->addLayout(hl_5);


        vl_calculateCalibration->addWidget(gb_calibrationPattern);

        label_HintResults = new QLabel(SingleCameraCalibration);
        label_HintResults->setObjectName(QString::fromUtf8("label_HintResults"));
        label_HintResults->setAlignment(Qt::AlignCenter);

        vl_calculateCalibration->addWidget(label_HintResults);

        btn_calculateCalibrationClicked = new QPushButton(SingleCameraCalibration);
        btn_calculateCalibrationClicked->setObjectName(QString::fromUtf8("btn_calculateCalibrationClicked"));

        vl_calculateCalibration->addWidget(btn_calculateCalibrationClicked);

        tableWidget = new QTableWidget(SingleCameraCalibration);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setDragDropOverwriteMode(false);

        vl_calculateCalibration->addWidget(tableWidget);

        line = new QFrame(SingleCameraCalibration);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vl_calculateCalibration->addWidget(line);


        horizontalLayout->addLayout(vl_calculateCalibration);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(SingleCameraCalibration);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 406, 341));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        vl_Cameras = new QVBoxLayout();
        vl_Cameras->setObjectName(QString::fromUtf8("vl_Cameras"));

        horizontalLayout_2->addLayout(vl_Cameras);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        hl_calibrationResults = new QHBoxLayout();
        hl_calibrationResults->setObjectName(QString::fromUtf8("hl_calibrationResults"));
        gl_calibrationResults = new QGridLayout();
        gl_calibrationResults->setObjectName(QString::fromUtf8("gl_calibrationResults"));
        gb_intrinsics = new QGroupBox(SingleCameraCalibration);
        gb_intrinsics->setObjectName(QString::fromUtf8("gb_intrinsics"));
        formLayout = new QFormLayout(gb_intrinsics);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(gb_intrinsics);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        le_focalLengthX = new QLineEdit(gb_intrinsics);
        le_focalLengthX->setObjectName(QString::fromUtf8("le_focalLengthX"));
        le_focalLengthX->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, le_focalLengthX);

        le_focalLengthY = new QLineEdit(gb_intrinsics);
        le_focalLengthY->setObjectName(QString::fromUtf8("le_focalLengthY"));
        le_focalLengthY->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, le_focalLengthY);

        le_princPointX = new QLineEdit(gb_intrinsics);
        le_princPointX->setObjectName(QString::fromUtf8("le_princPointX"));
        le_princPointX->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, le_princPointX);

        le_princPointY = new QLineEdit(gb_intrinsics);
        le_princPointY->setObjectName(QString::fromUtf8("le_princPointY"));
        le_princPointY->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, le_princPointY);

        label_2 = new QLabel(gb_intrinsics);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(gb_intrinsics);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(gb_intrinsics);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        gl_calibrationResults->addWidget(gb_intrinsics, 2, 0, 1, 1);

        gb_distortion = new QGroupBox(SingleCameraCalibration);
        gb_distortion->setObjectName(QString::fromUtf8("gb_distortion"));
        formLayout_2 = new QFormLayout(gb_distortion);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_5 = new QLabel(gb_distortion);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(gb_distortion);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(gb_distortion);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(gb_distortion);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(gb_distortion);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_9);

        le_K1 = new QLineEdit(gb_distortion);
        le_K1->setObjectName(QString::fromUtf8("le_K1"));
        le_K1->setEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, le_K1);

        le_K2 = new QLineEdit(gb_distortion);
        le_K2->setObjectName(QString::fromUtf8("le_K2"));
        le_K2->setEnabled(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, le_K2);

        le_K3 = new QLineEdit(gb_distortion);
        le_K3->setObjectName(QString::fromUtf8("le_K3"));
        le_K3->setEnabled(false);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, le_K3);

        le_K4 = new QLineEdit(gb_distortion);
        le_K4->setObjectName(QString::fromUtf8("le_K4"));
        le_K4->setEnabled(false);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, le_K4);

        le_K5 = new QLineEdit(gb_distortion);
        le_K5->setObjectName(QString::fromUtf8("le_K5"));
        le_K5->setEnabled(false);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, le_K5);


        gl_calibrationResults->addWidget(gb_distortion, 3, 0, 1, 1);

        groupBox = new QGroupBox(SingleCameraCalibration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout_3 = new QFormLayout(groupBox);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        le_error = new QLineEdit(groupBox);
        le_error->setObjectName(QString::fromUtf8("le_error"));
        le_error->setEnabled(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, le_error);

        le_size = new QLineEdit(groupBox);
        le_size->setObjectName(QString::fromUtf8("le_size"));
        le_size->setEnabled(false);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, le_size);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);


        gl_calibrationResults->addWidget(groupBox, 0, 0, 1, 1);


        hl_calibrationResults->addLayout(gl_calibrationResults);


        verticalLayout->addLayout(hl_calibrationResults);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(SingleCameraCalibration);

        QMetaObject::connectSlotsByName(SingleCameraCalibration);
    } // setupUi

    void retranslateUi(QWidget *SingleCameraCalibration)
    {
        SingleCameraCalibration->setWindowTitle(QApplication::translate("SingleCameraCalibration", "SingleCameraCalibration", 0, QApplication::UnicodeUTF8));
        gb_calibrationPattern->setTitle(QApplication::translate("SingleCameraCalibration", "\320\236\320\261\321\211\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \321\210\320\260\320\261\320\273\320\276\320\275\320\260 :", 0, QApplication::UnicodeUTF8));
        checkBox_Circle->setText(QApplication::translate("SingleCameraCalibration", "\320\250\320\260\320\261\320\273\320\276\320\275 \320\272\321\200\321\203\320\263\320\260", 0, QApplication::UnicodeUTF8));
        checkBox_Chessboard->setText(QApplication::translate("SingleCameraCalibration", "\320\250\320\260\320\261\320\273\320\276\320\275 \321\210\320\260\321\205\320\274\320\260\321\202\320\275\320\276\320\271 \320\264\320\276\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
        comboBox_CameraBreed->clear();
        comboBox_CameraBreed->insertItems(0, QStringList()
         << QApplication::translate("SingleCameraCalibration", "\320\222\320\270\320\264\320\270\320\274\321\213\320\271 \321\201\320\277\320\265\320\272\321\202\321\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SingleCameraCalibration", "\320\230\320\275\321\204\321\200\320\260\320\272\321\200\320\260\321\201\320\275\321\213\320\271 \321\201\320\277\320\265\320\272\321\202\321\200", 0, QApplication::UnicodeUTF8)
        );
        labelVerticalValue->setText(QApplication::translate("SingleCameraCalibration", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\320\270:", 0, QApplication::UnicodeUTF8));
        label_HorizontalValue->setText(QApplication::translate("SingleCameraCalibration", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\320\270:", 0, QApplication::UnicodeUTF8));
        label_SizeValue->setText(QApplication::translate("SingleCameraCalibration", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0, QApplication::UnicodeUTF8));
        label_HintResults->setText(QString());
        btn_calculateCalibrationClicked->setText(QApplication::translate("SingleCameraCalibration", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        gb_intrinsics->setTitle(QApplication::translate("SingleCameraCalibration", "\320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SingleCameraCalibration", "\320\244\320\276\320\272\321\203\321\201\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\277\320\276 X:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SingleCameraCalibration", "\320\244\320\276\320\272\321\203\321\201\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\277\320\276 Y:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SingleCameraCalibration", "\320\237\321\200\320\270\320\275\321\206\320\270\320\277\320\270\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260 \320\277\320\276 X:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SingleCameraCalibration", "\320\237\321\200\320\270\320\275\321\206\320\270\320\277\320\270\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260 \320\277\320\276 Y:", 0, QApplication::UnicodeUTF8));
        gb_distortion->setTitle(QApplication::translate("SingleCameraCalibration", "\320\224\320\270\321\201\321\202\320\276\321\200\321\201\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SingleCameraCalibration", "K1:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SingleCameraCalibration", "K2:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SingleCameraCalibration", "K3:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SingleCameraCalibration", "P1:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SingleCameraCalibration", "P2:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SingleCameraCalibration", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SingleCameraCalibration", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\270:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SingleCameraCalibration", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SingleCameraCalibration: public Ui_SingleCameraCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECAMERACALIBRATION_H
