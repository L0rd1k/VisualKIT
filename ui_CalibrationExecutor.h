/********************************************************************************
** Form generated from reading UI file 'CalibrationExecutor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONEXECUTOR_H
#define UI_CALIBRATIONEXECUTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibrationExecutor
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_CalculateCalibration;
    QGroupBox *groupBox_CalibrationPattern;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_Circle;
    QCheckBox *checkBox_Chessboard;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_CameraBreed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelVerticalValue;
    QSpinBox *spinBox_VerticalValue;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_HorizontalValue;
    QSpinBox *spinBox_HorizontalValue;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_SizeValue;
    QDoubleSpinBox *doubleSpinBox_SizeValue;
    QLabel *label_HintResults;
    QPushButton *btn_calculateCalibrationClicked;
    QListWidget *listWidget;
    QFrame *line;
    QVBoxLayout *verticalLayout_VideoVisualization;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_Cameras;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_VideoCapture;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox_pathOptions;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *lineEdit_videoIPPath;
    QCheckBox *checkBox_RealTime;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_ScreenShot;
    QToolButton *toolButton_VideoRecord;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_startStreaming;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_9;

    void setupUi(QWidget *CalibrationExecutor)
    {
        if (CalibrationExecutor->objectName().isEmpty())
            CalibrationExecutor->setObjectName(QString::fromUtf8("CalibrationExecutor"));
        CalibrationExecutor->resize(962, 904);
        CalibrationExecutor->setMinimumSize(QSize(850, 0));
        QFont font;
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        CalibrationExecutor->setFont(font);
        horizontalLayout = new QHBoxLayout(CalibrationExecutor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_CalculateCalibration = new QVBoxLayout();
        verticalLayout_CalculateCalibration->setObjectName(QString::fromUtf8("verticalLayout_CalculateCalibration"));
        groupBox_CalibrationPattern = new QGroupBox(CalibrationExecutor);
        groupBox_CalibrationPattern->setObjectName(QString::fromUtf8("groupBox_CalibrationPattern"));
        verticalLayout_5 = new QVBoxLayout(groupBox_CalibrationPattern);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_Circle = new QCheckBox(groupBox_CalibrationPattern);
        checkBox_Circle->setObjectName(QString::fromUtf8("checkBox_Circle"));
        checkBox_Circle->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_Circle);

        checkBox_Chessboard = new QCheckBox(groupBox_CalibrationPattern);
        checkBox_Chessboard->setObjectName(QString::fromUtf8("checkBox_Chessboard"));

        horizontalLayout_3->addWidget(checkBox_Chessboard);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_CameraBreed = new QComboBox(groupBox_CalibrationPattern);
        comboBox_CameraBreed->setObjectName(QString::fromUtf8("comboBox_CameraBreed"));

        horizontalLayout_5->addWidget(comboBox_CameraBreed);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelVerticalValue = new QLabel(groupBox_CalibrationPattern);
        labelVerticalValue->setObjectName(QString::fromUtf8("labelVerticalValue"));
        labelVerticalValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(labelVerticalValue);

        spinBox_VerticalValue = new QSpinBox(groupBox_CalibrationPattern);
        spinBox_VerticalValue->setObjectName(QString::fromUtf8("spinBox_VerticalValue"));

        horizontalLayout_6->addWidget(spinBox_VerticalValue);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_HorizontalValue = new QLabel(groupBox_CalibrationPattern);
        label_HorizontalValue->setObjectName(QString::fromUtf8("label_HorizontalValue"));
        label_HorizontalValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_HorizontalValue);

        spinBox_HorizontalValue = new QSpinBox(groupBox_CalibrationPattern);
        spinBox_HorizontalValue->setObjectName(QString::fromUtf8("spinBox_HorizontalValue"));

        horizontalLayout_7->addWidget(spinBox_HorizontalValue);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_SizeValue = new QLabel(groupBox_CalibrationPattern);
        label_SizeValue->setObjectName(QString::fromUtf8("label_SizeValue"));
        label_SizeValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_SizeValue);

        doubleSpinBox_SizeValue = new QDoubleSpinBox(groupBox_CalibrationPattern);
        doubleSpinBox_SizeValue->setObjectName(QString::fromUtf8("doubleSpinBox_SizeValue"));

        horizontalLayout_8->addWidget(doubleSpinBox_SizeValue);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_CalculateCalibration->addWidget(groupBox_CalibrationPattern);

        label_HintResults = new QLabel(CalibrationExecutor);
        label_HintResults->setObjectName(QString::fromUtf8("label_HintResults"));
        label_HintResults->setAlignment(Qt::AlignCenter);

        verticalLayout_CalculateCalibration->addWidget(label_HintResults);

        btn_calculateCalibrationClicked = new QPushButton(CalibrationExecutor);
        btn_calculateCalibrationClicked->setObjectName(QString::fromUtf8("btn_calculateCalibrationClicked"));

        verticalLayout_CalculateCalibration->addWidget(btn_calculateCalibrationClicked);

        listWidget = new QListWidget(CalibrationExecutor);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_CalculateCalibration->addWidget(listWidget);

        line = new QFrame(CalibrationExecutor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_CalculateCalibration->addWidget(line);


        horizontalLayout->addLayout(verticalLayout_CalculateCalibration);

        verticalLayout_VideoVisualization = new QVBoxLayout();
        verticalLayout_VideoVisualization->setObjectName(QString::fromUtf8("verticalLayout_VideoVisualization"));
        scrollArea = new QScrollArea(CalibrationExecutor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 465, 286));
        horizontalLayout_11 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_Cameras = new QVBoxLayout();
        verticalLayout_Cameras->setObjectName(QString::fromUtf8("verticalLayout_Cameras"));

        horizontalLayout_11->addLayout(verticalLayout_Cameras);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_VideoVisualization->addWidget(scrollArea);

        tableWidget = new QTableWidget(CalibrationExecutor);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_VideoVisualization->addWidget(tableWidget);

        groupBox_VideoCapture = new QGroupBox(CalibrationExecutor);
        groupBox_VideoCapture->setObjectName(QString::fromUtf8("groupBox_VideoCapture"));
        verticalLayout_6 = new QVBoxLayout(groupBox_VideoCapture);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox_VideoCapture);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        comboBox_pathOptions = new QComboBox(groupBox_VideoCapture);
        comboBox_pathOptions->setObjectName(QString::fromUtf8("comboBox_pathOptions"));
        comboBox_pathOptions->setMaxVisibleItems(10);
        comboBox_pathOptions->setInsertPolicy(QComboBox::InsertAtBottom);

        horizontalLayout_4->addWidget(comboBox_pathOptions);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(groupBox_VideoCapture);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_2);

        lineEdit_videoIPPath = new QLineEdit(groupBox_VideoCapture);
        lineEdit_videoIPPath->setObjectName(QString::fromUtf8("lineEdit_videoIPPath"));

        horizontalLayout_9->addWidget(lineEdit_videoIPPath);


        verticalLayout_6->addLayout(horizontalLayout_9);

        checkBox_RealTime = new QCheckBox(groupBox_VideoCapture);
        checkBox_RealTime->setObjectName(QString::fromUtf8("checkBox_RealTime"));

        verticalLayout_6->addWidget(checkBox_RealTime);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        toolButton_ScreenShot = new QToolButton(groupBox_VideoCapture);
        toolButton_ScreenShot->setObjectName(QString::fromUtf8("toolButton_ScreenShot"));

        horizontalLayout_10->addWidget(toolButton_ScreenShot);

        toolButton_VideoRecord = new QToolButton(groupBox_VideoCapture);
        toolButton_VideoRecord->setObjectName(QString::fromUtf8("toolButton_VideoRecord"));

        horizontalLayout_10->addWidget(toolButton_VideoRecord);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_10);

        btn_startStreaming = new QPushButton(groupBox_VideoCapture);
        btn_startStreaming->setObjectName(QString::fromUtf8("btn_startStreaming"));

        verticalLayout_6->addWidget(btn_startStreaming);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);


        verticalLayout_VideoVisualization->addWidget(groupBox_VideoCapture);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        verticalLayout_VideoVisualization->addLayout(verticalLayout_9);


        horizontalLayout->addLayout(verticalLayout_VideoVisualization);


        retranslateUi(CalibrationExecutor);

        QMetaObject::connectSlotsByName(CalibrationExecutor);
    } // setupUi

    void retranslateUi(QWidget *CalibrationExecutor)
    {
        CalibrationExecutor->setWindowTitle(QApplication::translate("CalibrationExecutor", "CalibrationExecutor", 0, QApplication::UnicodeUTF8));
        groupBox_CalibrationPattern->setTitle(QApplication::translate("CalibrationExecutor", "\320\236\320\261\321\211\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \321\210\320\260\320\261\320\273\320\276\320\275\320\260 :", 0, QApplication::UnicodeUTF8));
        checkBox_Circle->setText(QApplication::translate("CalibrationExecutor", "\320\250\320\260\320\261\320\273\320\276\320\275 \320\272\321\200\321\203\320\263\320\260", 0, QApplication::UnicodeUTF8));
        checkBox_Chessboard->setText(QApplication::translate("CalibrationExecutor", "\320\250\320\260\320\261\320\273\320\276\320\275 \321\210\320\260\321\205\320\274\320\260\321\202\320\275\320\276\320\271 \320\264\320\276\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
        comboBox_CameraBreed->clear();
        comboBox_CameraBreed->insertItems(0, QStringList()
         << QApplication::translate("CalibrationExecutor", "\320\222\320\270\320\264\320\270\320\274\321\213\320\271 \321\201\320\277\320\265\320\272\321\202\321\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CalibrationExecutor", "\320\230\320\275\321\204\321\200\320\260\320\272\321\200\320\260\321\201\320\275\321\213\320\271 \321\201\320\277\320\265\320\272\321\202\321\200", 0, QApplication::UnicodeUTF8)
        );
        labelVerticalValue->setText(QApplication::translate("CalibrationExecutor", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\320\270:", 0, QApplication::UnicodeUTF8));
        label_HorizontalValue->setText(QApplication::translate("CalibrationExecutor", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\320\270:", 0, QApplication::UnicodeUTF8));
        label_SizeValue->setText(QApplication::translate("CalibrationExecutor", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0, QApplication::UnicodeUTF8));
        label_HintResults->setText(QString());
        btn_calculateCalibrationClicked->setText(QApplication::translate("CalibrationExecutor", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        groupBox_VideoCapture->setTitle(QApplication::translate("CalibrationExecutor", "\320\227\320\260\321\205\320\262\320\260\321\202 \320\262\320\270\320\264\320\265\320\276\320\277\320\276\321\202\320\276\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CalibrationExecutor", "\320\237\321\203\321\202\320\270 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CalibrationExecutor", "\320\222\320\262\320\265\321\201\321\202\320\270 \321\201\320\262\320\276\320\271 \320\277\321\203\321\202\321\214 :", 0, QApplication::UnicodeUTF8));
        checkBox_RealTime->setText(QApplication::translate("CalibrationExecutor", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \321\210\320\260\320\261\320\273\320\276\320\275\320\260 \320\262 RealTime", 0, QApplication::UnicodeUTF8));
        toolButton_ScreenShot->setText(QApplication::translate("CalibrationExecutor", "Screenshot", 0, QApplication::UnicodeUTF8));
        toolButton_VideoRecord->setText(QApplication::translate("CalibrationExecutor", "Record", 0, QApplication::UnicodeUTF8));
        btn_startStreaming->setText(QApplication::translate("CalibrationExecutor", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalibrationExecutor: public Ui_CalibrationExecutor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONEXECUTOR_H
