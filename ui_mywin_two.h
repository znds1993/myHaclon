/********************************************************************************
** Form generated from reading UI file 'mywin_two.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIN_TWO_H
#define UI_MYWIN_TWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mywin_two
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Mywin_two)
    {
        if (Mywin_two->objectName().isEmpty())
            Mywin_two->setObjectName(QString::fromUtf8("Mywin_two"));
        Mywin_two->resize(953, 390);
        Mywin_two->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(Mywin_two);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Mywin_two);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(Mywin_two);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        stackedWidget->setFrameShadow(QFrame::Plain);
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 150));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 911, 302));
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 911, 302));
        scrollArea_2->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 3);

        pushButton_2 = new QPushButton(Mywin_two);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Mywin_two);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Mywin_two);
    } // setupUi

    void retranslateUi(QWidget *Mywin_two)
    {
        Mywin_two->setWindowTitle(QApplication::translate("Mywin_two", "Form", nullptr));
        pushButton->setText(QApplication::translate("Mywin_two", "\344\277\235\345\255\230\345\233\276\345\203\217\345\214\272", nullptr));
        pushButton_2->setText(QApplication::translate("Mywin_two", "\350\276\223\345\207\272\345\233\276\345\203\217\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mywin_two: public Ui_Mywin_two {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIN_TWO_H
