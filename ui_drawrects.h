/********************************************************************************
** Form generated from reading UI file 'drawrects.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWRECTS_H
#define UI_DRAWRECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawRects
{
public:

    void setupUi(QWidget *DrawRects)
    {
        if (DrawRects->objectName().isEmpty())
            DrawRects->setObjectName(QString::fromUtf8("DrawRects"));
        DrawRects->resize(400, 300);

        retranslateUi(DrawRects);

        QMetaObject::connectSlotsByName(DrawRects);
    } // setupUi

    void retranslateUi(QWidget *DrawRects)
    {
        DrawRects->setWindowTitle(QApplication::translate("DrawRects", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawRects: public Ui_DrawRects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWRECTS_H
