/********************************************************************************
** Form generated from reading UI file 'mywin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIN_H
#define UI_MYWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWin
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *MyWin)
    {
        if (MyWin->objectName().isEmpty())
            MyWin->setObjectName(QString::fromUtf8("MyWin"));
        MyWin->resize(681, 462);
        gridLayout = new QGridLayout(MyWin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(MyWin);

        QMetaObject::connectSlotsByName(MyWin);
    } // setupUi

    void retranslateUi(QWidget *MyWin)
    {
        MyWin->setWindowTitle(QApplication::translate("MyWin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWin: public Ui_MyWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIN_H
