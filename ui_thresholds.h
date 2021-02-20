/********************************************************************************
** Form generated from reading UI file 'thresholds.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDS_H
#define UI_THRESHOLDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Thresholds
{
public:

    void setupUi(QWidget *Thresholds)
    {
        if (Thresholds->objectName().isEmpty())
            Thresholds->setObjectName(QString::fromUtf8("Thresholds"));
        Thresholds->resize(400, 300);

        retranslateUi(Thresholds);

        QMetaObject::connectSlotsByName(Thresholds);
    } // setupUi

    void retranslateUi(QWidget *Thresholds)
    {
        Thresholds->setWindowTitle(QApplication::translate("Thresholds", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Thresholds: public Ui_Thresholds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDS_H
