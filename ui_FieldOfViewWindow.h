/********************************************************************************
** Form generated from reading UI file 'FieldOfViewWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELDOFVIEWWINDOW_H
#define UI_FIELDOFVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FieldOfViewWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *gb_CalculateFieldOfView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *bl_boxFileName;
    QLabel *lbl_unused_findfile;
    QLineEdit *le_filename;
    QLabel *lbl_unused_extenstion;
    QPushButton *btn_calculateFOV;
    QLabel *lbl_FOVResults;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FieldOfViewWindow)
    {
        if (FieldOfViewWindow->objectName().isEmpty())
            FieldOfViewWindow->setObjectName(QString::fromUtf8("FieldOfViewWindow"));
        FieldOfViewWindow->resize(456, 176);
        horizontalLayout = new QHBoxLayout(FieldOfViewWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gb_CalculateFieldOfView = new QGroupBox(FieldOfViewWindow);
        gb_CalculateFieldOfView->setObjectName(QString::fromUtf8("gb_CalculateFieldOfView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gb_CalculateFieldOfView->sizePolicy().hasHeightForWidth());
        gb_CalculateFieldOfView->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        gb_CalculateFieldOfView->setFont(font);
        gb_CalculateFieldOfView->setFocusPolicy(Qt::NoFocus);
        gb_CalculateFieldOfView->setContextMenuPolicy(Qt::NoContextMenu);
        gb_CalculateFieldOfView->setAcceptDrops(false);
        gb_CalculateFieldOfView->setAutoFillBackground(false);
        gb_CalculateFieldOfView->setCheckable(false);
        verticalLayout = new QVBoxLayout(gb_CalculateFieldOfView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bl_boxFileName = new QHBoxLayout();
        bl_boxFileName->setObjectName(QString::fromUtf8("bl_boxFileName"));
        lbl_unused_findfile = new QLabel(gb_CalculateFieldOfView);
        lbl_unused_findfile->setObjectName(QString::fromUtf8("lbl_unused_findfile"));

        bl_boxFileName->addWidget(lbl_unused_findfile);

        le_filename = new QLineEdit(gb_CalculateFieldOfView);
        le_filename->setObjectName(QString::fromUtf8("le_filename"));

        bl_boxFileName->addWidget(le_filename);

        lbl_unused_extenstion = new QLabel(gb_CalculateFieldOfView);
        lbl_unused_extenstion->setObjectName(QString::fromUtf8("lbl_unused_extenstion"));

        bl_boxFileName->addWidget(lbl_unused_extenstion);


        verticalLayout->addLayout(bl_boxFileName);

        btn_calculateFOV = new QPushButton(gb_CalculateFieldOfView);
        btn_calculateFOV->setObjectName(QString::fromUtf8("btn_calculateFOV"));

        verticalLayout->addWidget(btn_calculateFOV);

        lbl_FOVResults = new QLabel(gb_CalculateFieldOfView);
        lbl_FOVResults->setObjectName(QString::fromUtf8("lbl_FOVResults"));
        lbl_FOVResults->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_FOVResults);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(gb_CalculateFieldOfView);


        retranslateUi(FieldOfViewWindow);

        QMetaObject::connectSlotsByName(FieldOfViewWindow);
    } // setupUi

    void retranslateUi(QWidget *FieldOfViewWindow)
    {
        FieldOfViewWindow->setWindowTitle(QApplication::translate("FieldOfViewWindow", "FieldOfViewWindow", 0, QApplication::UnicodeUTF8));
        gb_CalculateFieldOfView->setTitle(QApplication::translate("FieldOfViewWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\203\320\263\320\276\320\273 \320\276\320\261\320\267\320\276\321\200\320\260:", 0, QApplication::UnicodeUTF8));
        lbl_unused_findfile->setText(QApplication::translate("FieldOfViewWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 : ", 0, QApplication::UnicodeUTF8));
        lbl_unused_extenstion->setText(QApplication::translate("FieldOfViewWindow", ".yml", 0, QApplication::UnicodeUTF8));
        btn_calculateFOV->setText(QApplication::translate("FieldOfViewWindow", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\203\320\263\320\276\320\273 \320\276\320\261\320\267\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lbl_FOVResults->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FieldOfViewWindow: public Ui_FieldOfViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDOFVIEWWINDOW_H
