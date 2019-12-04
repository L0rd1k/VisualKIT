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
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibrationExecutor
{
public:
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *page_CalculateCalibration;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_FIndFile;
    QLineEdit *lineEdit_IntrinsicsFileName;
    QLabel *label_YML;
    QPushButton *btn_calculateFOVClicked;
    QLabel *label_FOV;
    QFrame *line_2;
    QGroupBox *groupBox;
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
    QPushButton *btn_calculateCalibrationClicked;
    QFrame *line;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox_pathOptions;
    QLineEdit *lineEdit_videoIPPath;
    QPushButton *btn_startStreaming;
    QLabel *label_HintResults;
    QListWidget *listWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_Cameras;

    void setupUi(QWidget *CalibrationExecutor)
    {
        if (CalibrationExecutor->objectName().isEmpty())
            CalibrationExecutor->setObjectName(QString::fromUtf8("CalibrationExecutor"));
        CalibrationExecutor->resize(824, 904);
        QFont font;
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        CalibrationExecutor->setFont(font);
        horizontalLayout = new QHBoxLayout(CalibrationExecutor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolBox = new QToolBox(CalibrationExecutor);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(400, 0));
        page_CalculateCalibration = new QWidget();
        page_CalculateCalibration->setObjectName(QString::fromUtf8("page_CalculateCalibration"));
        page_CalculateCalibration->setGeometry(QRect(0, 0, 401, 842));
        verticalLayout_4 = new QVBoxLayout(page_CalculateCalibration);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(page_CalculateCalibration);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        groupBox_3->setFont(font1);
        groupBox_3->setFocusPolicy(Qt::NoFocus);
        groupBox_3->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox_3->setAcceptDrops(false);
        groupBox_3->setAutoFillBackground(false);
        groupBox_3->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_FIndFile = new QLabel(groupBox_3);
        label_FIndFile->setObjectName(QString::fromUtf8("label_FIndFile"));

        horizontalLayout_2->addWidget(label_FIndFile);

        lineEdit_IntrinsicsFileName = new QLineEdit(groupBox_3);
        lineEdit_IntrinsicsFileName->setObjectName(QString::fromUtf8("lineEdit_IntrinsicsFileName"));

        horizontalLayout_2->addWidget(lineEdit_IntrinsicsFileName);

        label_YML = new QLabel(groupBox_3);
        label_YML->setObjectName(QString::fromUtf8("label_YML"));

        horizontalLayout_2->addWidget(label_YML);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_calculateFOVClicked = new QPushButton(groupBox_3);
        btn_calculateFOVClicked->setObjectName(QString::fromUtf8("btn_calculateFOVClicked"));

        verticalLayout->addWidget(btn_calculateFOVClicked);

        label_FOV = new QLabel(groupBox_3);
        label_FOV->setObjectName(QString::fromUtf8("label_FOV"));
        label_FOV->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_FOV);


        verticalLayout_3->addWidget(groupBox_3);

        line_2 = new QFrame(page_CalculateCalibration);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        groupBox = new QGroupBox(page_CalculateCalibration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_Circle = new QCheckBox(groupBox);
        checkBox_Circle->setObjectName(QString::fromUtf8("checkBox_Circle"));
        checkBox_Circle->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_Circle);

        checkBox_Chessboard = new QCheckBox(groupBox);
        checkBox_Chessboard->setObjectName(QString::fromUtf8("checkBox_Chessboard"));

        horizontalLayout_3->addWidget(checkBox_Chessboard);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_CameraBreed = new QComboBox(groupBox);
        comboBox_CameraBreed->setObjectName(QString::fromUtf8("comboBox_CameraBreed"));

        horizontalLayout_5->addWidget(comboBox_CameraBreed);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelVerticalValue = new QLabel(groupBox);
        labelVerticalValue->setObjectName(QString::fromUtf8("labelVerticalValue"));
        labelVerticalValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(labelVerticalValue);

        spinBox_VerticalValue = new QSpinBox(groupBox);
        spinBox_VerticalValue->setObjectName(QString::fromUtf8("spinBox_VerticalValue"));

        horizontalLayout_6->addWidget(spinBox_VerticalValue);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_HorizontalValue = new QLabel(groupBox);
        label_HorizontalValue->setObjectName(QString::fromUtf8("label_HorizontalValue"));
        label_HorizontalValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_HorizontalValue);

        spinBox_HorizontalValue = new QSpinBox(groupBox);
        spinBox_HorizontalValue->setObjectName(QString::fromUtf8("spinBox_HorizontalValue"));

        horizontalLayout_7->addWidget(spinBox_HorizontalValue);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_SizeValue = new QLabel(groupBox);
        label_SizeValue->setObjectName(QString::fromUtf8("label_SizeValue"));
        label_SizeValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_SizeValue);

        doubleSpinBox_SizeValue = new QDoubleSpinBox(groupBox);
        doubleSpinBox_SizeValue->setObjectName(QString::fromUtf8("doubleSpinBox_SizeValue"));

        horizontalLayout_8->addWidget(doubleSpinBox_SizeValue);


        verticalLayout_5->addLayout(horizontalLayout_8);

        btn_calculateCalibrationClicked = new QPushButton(groupBox);
        btn_calculateCalibrationClicked->setObjectName(QString::fromUtf8("btn_calculateCalibrationClicked"));

        verticalLayout_5->addWidget(btn_calculateCalibrationClicked);

        btn_calculateCalibrationClicked->raise();

        verticalLayout_3->addWidget(groupBox);

        line = new QFrame(page_CalculateCalibration);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        groupBox_2 = new QGroupBox(page_CalculateCalibration);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        groupBox_2->setPalette(palette);
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        comboBox_pathOptions = new QComboBox(groupBox_2);
        comboBox_pathOptions->setObjectName(QString::fromUtf8("comboBox_pathOptions"));

        verticalLayout_6->addWidget(comboBox_pathOptions);

        lineEdit_videoIPPath = new QLineEdit(groupBox_2);
        lineEdit_videoIPPath->setObjectName(QString::fromUtf8("lineEdit_videoIPPath"));

        verticalLayout_6->addWidget(lineEdit_videoIPPath);

        btn_startStreaming = new QPushButton(groupBox_2);
        btn_startStreaming->setObjectName(QString::fromUtf8("btn_startStreaming"));

        verticalLayout_6->addWidget(btn_startStreaming);


        verticalLayout_3->addWidget(groupBox_2);

        label_HintResults = new QLabel(page_CalculateCalibration);
        label_HintResults->setObjectName(QString::fromUtf8("label_HintResults"));
        label_HintResults->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_HintResults);

        listWidget = new QListWidget(page_CalculateCalibration);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        verticalLayout_4->addLayout(verticalLayout_3);

        toolBox->addItem(page_CalculateCalibration, QString::fromUtf8("\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217\320\274"));

        horizontalLayout->addWidget(toolBox);

        scrollArea = new QScrollArea(CalibrationExecutor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(400, 400));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 884));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_Cameras = new QVBoxLayout();
        verticalLayout_Cameras->setObjectName(QString::fromUtf8("verticalLayout_Cameras"));

        verticalLayout_2->addLayout(verticalLayout_Cameras);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(CalibrationExecutor);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CalibrationExecutor);
    } // setupUi

    void retranslateUi(QWidget *CalibrationExecutor)
    {
        CalibrationExecutor->setWindowTitle(QApplication::translate("CalibrationExecutor", "CalibrationExecutor", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CalibrationExecutor", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\203\320\263\320\276\320\273 \320\276\320\261\320\267\320\276\321\200\320\260:", 0, QApplication::UnicodeUTF8));
        label_FIndFile->setText(QApplication::translate("CalibrationExecutor", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 : ", 0, QApplication::UnicodeUTF8));
        label_YML->setText(QApplication::translate("CalibrationExecutor", ".yml", 0, QApplication::UnicodeUTF8));
        btn_calculateFOVClicked->setText(QApplication::translate("CalibrationExecutor", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\203\320\263\320\276\320\273 \320\276\320\261\320\267\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_FOV->setText(QString());
        groupBox->setTitle(QApplication::translate("CalibrationExecutor", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260:", 0, QApplication::UnicodeUTF8));
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
        btn_calculateCalibrationClicked->setText(QApplication::translate("CalibrationExecutor", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CalibrationExecutor", "\320\227\320\260\321\205\320\262\320\260\321\202 \320\262\320\270\320\264\320\265\320\276\320\277\320\276\321\202\320\276\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        btn_startStreaming->setText(QApplication::translate("CalibrationExecutor", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_HintResults->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_CalculateCalibration), QApplication::translate("CalibrationExecutor", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\277\320\276 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217\320\274", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalibrationExecutor: public Ui_CalibrationExecutor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONEXECUTOR_H
