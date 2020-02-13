/********************************************************************************
** Form generated from reading UI file 'MainMenuWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUWINDOW_H
#define UI_MAINMENUWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vl_execution;
    QFrame *line;
    QVBoxLayout *vl_regimes;
    QGroupBox *gb_regimes;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pb_videostream;
    QPushButton *pb_fov;
    QPushButton *pb_singlecalib;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MainMenuWindow)
    {
        if (MainMenuWindow->objectName().isEmpty())
            MainMenuWindow->setObjectName(QString::fromUtf8("MainMenuWindow"));
        MainMenuWindow->resize(1187, 722);
        horizontalLayout_2 = new QHBoxLayout(MainMenuWindow);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        vl_execution = new QVBoxLayout();
        vl_execution->setObjectName(QString::fromUtf8("vl_execution"));

        horizontalLayout_2->addLayout(vl_execution);

        line = new QFrame(MainMenuWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        vl_regimes = new QVBoxLayout();
        vl_regimes->setObjectName(QString::fromUtf8("vl_regimes"));
        gb_regimes = new QGroupBox(MainMenuWindow);
        gb_regimes->setObjectName(QString::fromUtf8("gb_regimes"));
        verticalLayout_3 = new QVBoxLayout(gb_regimes);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pb_videostream = new QPushButton(gb_regimes);
        pb_videostream->setObjectName(QString::fromUtf8("pb_videostream"));

        verticalLayout_3->addWidget(pb_videostream);

        pb_fov = new QPushButton(gb_regimes);
        pb_fov->setObjectName(QString::fromUtf8("pb_fov"));
        pb_fov->setIconSize(QSize(25, 25));

        verticalLayout_3->addWidget(pb_fov);

        pb_singlecalib = new QPushButton(gb_regimes);
        pb_singlecalib->setObjectName(QString::fromUtf8("pb_singlecalib"));

        verticalLayout_3->addWidget(pb_singlecalib);


        vl_regimes->addWidget(gb_regimes);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vl_regimes->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(vl_regimes);


        retranslateUi(MainMenuWindow);

        QMetaObject::connectSlotsByName(MainMenuWindow);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWindow)
    {
        MainMenuWindow->setWindowTitle(QApplication::translate("MainMenuWindow", "MainMenuWindow", 0, QApplication::UnicodeUTF8));
        gb_regimes->setTitle(QApplication::translate("MainMenuWindow", "\320\240\320\265\320\266\320\270\320\274\321\213:", 0, QApplication::UnicodeUTF8));
        pb_videostream->setText(QApplication::translate("MainMenuWindow", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \321\201 \320\262\320\270\320\264\320\265\320\276\320\277\320\276\321\202\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pb_fov->setText(QApplication::translate("MainMenuWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\203\320\263\320\276\320\273 \320\276\320\261\320\267\320\276\321\200\320\260 \320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        pb_singlecalib->setText(QApplication::translate("MainMenuWindow", "\320\236\321\202\320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWindow: public Ui_MainMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWINDOW_H
