/********************************************************************************
** Form generated from reading UI file 'CamerasVideoCapture.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERASVIDEOCAPTURE_H
#define UI_CAMERASVIDEOCAPTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamerasVideoCapture
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_VideoCapture;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget;
    QFormLayout *formLayout_CaptureParam;
    QLabel *lbl_1;
    QComboBox *comboBox_pathOptions;
    QLabel *lbl_2;
    QLineEdit *lineEdit_videoIPPath;
    QCheckBox *checkBox_RealTime;
    QPushButton *btn_startStreaming;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QToolButton *toolButton_VideoRecord;
    QToolButton *toolButton_ScreenShot;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *CamerasVideoCapture)
    {
        if (CamerasVideoCapture->objectName().isEmpty())
            CamerasVideoCapture->setObjectName(QString::fromUtf8("CamerasVideoCapture"));
        CamerasVideoCapture->resize(989, 770);
        horizontalLayout = new QHBoxLayout(CamerasVideoCapture);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_VideoCapture = new QGroupBox(CamerasVideoCapture);
        groupBox_VideoCapture->setObjectName(QString::fromUtf8("groupBox_VideoCapture"));
        verticalLayout_6 = new QVBoxLayout(groupBox_VideoCapture);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableWidget = new QTableWidget(groupBox_VideoCapture);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMaximumSize(QSize(16777215, 200));

        verticalLayout_6->addWidget(tableWidget);

        formLayout_CaptureParam = new QFormLayout();
        formLayout_CaptureParam->setObjectName(QString::fromUtf8("formLayout_CaptureParam"));
        lbl_1 = new QLabel(groupBox_VideoCapture);
        lbl_1->setObjectName(QString::fromUtf8("lbl_1"));
        lbl_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_CaptureParam->setWidget(0, QFormLayout::LabelRole, lbl_1);

        comboBox_pathOptions = new QComboBox(groupBox_VideoCapture);
        comboBox_pathOptions->setObjectName(QString::fromUtf8("comboBox_pathOptions"));
        comboBox_pathOptions->setMaxVisibleItems(10);
        comboBox_pathOptions->setInsertPolicy(QComboBox::InsertAtBottom);

        formLayout_CaptureParam->setWidget(0, QFormLayout::FieldRole, comboBox_pathOptions);

        lbl_2 = new QLabel(groupBox_VideoCapture);
        lbl_2->setObjectName(QString::fromUtf8("lbl_2"));
        lbl_2->setAlignment(Qt::AlignCenter);

        formLayout_CaptureParam->setWidget(1, QFormLayout::LabelRole, lbl_2);

        lineEdit_videoIPPath = new QLineEdit(groupBox_VideoCapture);
        lineEdit_videoIPPath->setObjectName(QString::fromUtf8("lineEdit_videoIPPath"));

        formLayout_CaptureParam->setWidget(1, QFormLayout::FieldRole, lineEdit_videoIPPath);


        verticalLayout_6->addLayout(formLayout_CaptureParam);

        checkBox_RealTime = new QCheckBox(groupBox_VideoCapture);
        checkBox_RealTime->setObjectName(QString::fromUtf8("checkBox_RealTime"));

        verticalLayout_6->addWidget(checkBox_RealTime);

        btn_startStreaming = new QPushButton(groupBox_VideoCapture);
        btn_startStreaming->setObjectName(QString::fromUtf8("btn_startStreaming"));

        verticalLayout_6->addWidget(btn_startStreaming);

        groupBox = new QGroupBox(groupBox_VideoCapture);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        toolButton_VideoRecord = new QToolButton(groupBox);
        toolButton_VideoRecord->setObjectName(QString::fromUtf8("toolButton_VideoRecord"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_VideoRecord->sizePolicy().hasHeightForWidth());
        toolButton_VideoRecord->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, toolButton_VideoRecord);

        toolButton_ScreenShot = new QToolButton(groupBox);
        toolButton_ScreenShot->setObjectName(QString::fromUtf8("toolButton_ScreenShot"));
        sizePolicy.setHeightForWidth(toolButton_ScreenShot->sizePolicy().hasHeightForWidth());
        toolButton_ScreenShot->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::FieldRole, toolButton_ScreenShot);


        verticalLayout_6->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox_VideoCapture);

        scrollArea = new QScrollArea(CamerasVideoCapture);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 750));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(CamerasVideoCapture);

        QMetaObject::connectSlotsByName(CamerasVideoCapture);
    } // setupUi

    void retranslateUi(QWidget *CamerasVideoCapture)
    {
        CamerasVideoCapture->setWindowTitle(QApplication::translate("CamerasVideoCapture", "CamerasVideoCapture", 0, QApplication::UnicodeUTF8));
        groupBox_VideoCapture->setTitle(QApplication::translate("CamerasVideoCapture", "\320\227\320\260\321\205\320\262\320\260\321\202 \320\262\320\270\320\264\320\265\320\276\320\277\320\276\321\202\320\276\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        lbl_1->setText(QApplication::translate("CamerasVideoCapture", "\320\237\321\203\321\202\320\270 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216:", 0, QApplication::UnicodeUTF8));
        lbl_2->setText(QApplication::translate("CamerasVideoCapture", "\320\222\320\262\320\265\321\201\321\202\320\270 \321\201\320\262\320\276\320\271 \320\277\321\203\321\202\321\214 :", 0, QApplication::UnicodeUTF8));
        checkBox_RealTime->setText(QApplication::translate("CamerasVideoCapture", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\276\321\207\320\275\320\276\320\263\320\276 \321\210\320\260\320\261\320\273\320\276\320\275\320\260 \320\262 RealTime", 0, QApplication::UnicodeUTF8));
        btn_startStreaming->setText(QApplication::translate("CamerasVideoCapture", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CamerasVideoCapture", "\320\240\320\265\320\266\320\270\320\274\321\213", 0, QApplication::UnicodeUTF8));
        toolButton_VideoRecord->setText(QApplication::translate("CamerasVideoCapture", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\262\320\270\320\264\320\265\320\276\320\277\320\276\321\202\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
        toolButton_ScreenShot->setText(QApplication::translate("CamerasVideoCapture", "\320\227\320\260\321\205\320\262\320\260\321\202 \320\272\320\260\320\264\321\200\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CamerasVideoCapture: public Ui_CamerasVideoCapture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERASVIDEOCAPTURE_H
