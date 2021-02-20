/********************************************************************************
** Form generated from reading UI file 'drawellipses.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWELLIPSES_H
#define UI_DRAWELLIPSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawEllipses
{
public:
    QSlider *horizontalSlider;

    void setupUi(QWidget *DrawEllipses)
    {
        if (DrawEllipses->objectName().isEmpty())
            DrawEllipses->setObjectName(QString::fromUtf8("DrawEllipses"));
        DrawEllipses->resize(400, 300);
        horizontalSlider = new QSlider(DrawEllipses);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(130, 200, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(DrawEllipses);

        QMetaObject::connectSlotsByName(DrawEllipses);
    } // setupUi

    void retranslateUi(QWidget *DrawEllipses)
    {
        DrawEllipses->setWindowTitle(QApplication::translate("DrawEllipses", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawEllipses: public Ui_DrawEllipses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWELLIPSES_H
