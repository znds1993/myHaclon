/********************************************************************************
** Form generated from reading UI file 'openingcircle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENINGCIRCLE_H
#define UI_OPENINGCIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpeningCircle
{
public:

    void setupUi(QWidget *OpeningCircle)
    {
        if (OpeningCircle->objectName().isEmpty())
            OpeningCircle->setObjectName(QString::fromUtf8("OpeningCircle"));
        OpeningCircle->resize(400, 300);

        retranslateUi(OpeningCircle);

        QMetaObject::connectSlotsByName(OpeningCircle);
    } // setupUi

    void retranslateUi(QWidget *OpeningCircle)
    {
        OpeningCircle->setWindowTitle(QApplication::translate("OpeningCircle", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpeningCircle: public Ui_OpeningCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENINGCIRCLE_H
