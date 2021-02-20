/********************************************************************************
** Form generated from reading UI file 'drawrotaterects.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWROTATERECTS_H
#define UI_DRAWROTATERECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawRotateRects
{
public:

    void setupUi(QWidget *DrawRotateRects)
    {
        if (DrawRotateRects->objectName().isEmpty())
            DrawRotateRects->setObjectName(QString::fromUtf8("DrawRotateRects"));
        DrawRotateRects->resize(400, 300);

        retranslateUi(DrawRotateRects);

        QMetaObject::connectSlotsByName(DrawRotateRects);
    } // setupUi

    void retranslateUi(QWidget *DrawRotateRects)
    {
        DrawRotateRects->setWindowTitle(QApplication::translate("DrawRotateRects", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawRotateRects: public Ui_DrawRotateRects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWROTATERECTS_H
