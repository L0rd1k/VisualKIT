/********************************************************************************
** Form generated from reading UI file 'FindFiles.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFILES_H
#define UI_FINDFILES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FindFiles
{
public:

    void setupUi(QDialog *FindFiles)
    {
        if (FindFiles->objectName().isEmpty())
            FindFiles->setObjectName(QString::fromUtf8("FindFiles"));
        FindFiles->resize(400, 300);

        retranslateUi(FindFiles);

        QMetaObject::connectSlotsByName(FindFiles);
    } // setupUi

    void retranslateUi(QDialog *FindFiles)
    {
        FindFiles->setWindowTitle(QApplication::translate("FindFiles", "FindFiles", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FindFiles: public Ui_FindFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFILES_H
