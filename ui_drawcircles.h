/********************************************************************************
** Form generated from reading UI file 'drawcircles.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWCIRCLES_H
#define UI_DRAWCIRCLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawCircles
{
public:

    void setupUi(QWidget *DrawCircles)
    {
        if (DrawCircles->objectName().isEmpty())
            DrawCircles->setObjectName(QString::fromUtf8("DrawCircles"));
        DrawCircles->resize(702, 465);

        retranslateUi(DrawCircles);

        QMetaObject::connectSlotsByName(DrawCircles);
    } // setupUi

    void retranslateUi(QWidget *DrawCircles)
    {
        DrawCircles->setWindowTitle(QApplication::translate("DrawCircles", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawCircles: public Ui_DrawCircles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWCIRCLES_H
