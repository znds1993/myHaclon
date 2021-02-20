/********************************************************************************
** Form generated from reading UI file 'closingcircle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSINGCIRCLE_H
#define UI_CLOSINGCIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClosingCircle
{
public:

    void setupUi(QWidget *ClosingCircle)
    {
        if (ClosingCircle->objectName().isEmpty())
            ClosingCircle->setObjectName(QString::fromUtf8("ClosingCircle"));
        ClosingCircle->resize(400, 300);

        retranslateUi(ClosingCircle);

        QMetaObject::connectSlotsByName(ClosingCircle);
    } // setupUi

    void retranslateUi(QWidget *ClosingCircle)
    {
        ClosingCircle->setWindowTitle(QApplication::translate("ClosingCircle", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClosingCircle: public Ui_ClosingCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSINGCIRCLE_H
