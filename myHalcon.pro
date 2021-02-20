#-------------------------------------------------
#
# Project created by QtCreator 2021-01-20T16:32:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myHalcon
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        createoperator.cpp \
        halconOperator/closingcircle.cpp \
        halconOperator/drawcircles.cpp \
        halconOperator/drawellipses.cpp \
        halconOperator/drawrects.cpp \
        halconOperator/drawrotaterects.cpp \
        halconOperator/h_operators.cpp \
        halconOperator/openingcircle.cpp \
        halconOperator/thresholds.cpp \
        main.cpp \
        mainwindow.cpp \
        myenum.cpp \
        mythread.cpp \
        mywin.cpp \
        mywin_three.cpp \
        mywin_two.cpp

HEADERS += \
        createoperator.h \
        halconOperator/closingcircle.h \
        halconOperator/drawcircles.h \
        halconOperator/drawellipses.h \
        halconOperator/drawrects.h \
        halconOperator/drawrotaterects.h \
        halconOperator/h_operators.h \
        halconOperator/openingcircle.h \
        halconOperator/thresholds.h \
        mainwindow.h \
        myenum.h \
        mythread.h \
        mywin.h \
        mywin_three.h \
        mywin_two.h

FORMS += \
        halconOperator/closingcircle.ui \
        halconOperator/drawcircles.ui \
        halconOperator/drawellipses.ui \
        halconOperator/drawrects.ui \
        halconOperator/drawrotaterects.ui \
        halconOperator/openingcircle.ui \
        halconOperator/thresholds.ui \
        mainwindow.ui \
        mywin.ui \
        mywin_three.ui \
        mywin_two.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += "D:/halcon_zhengban/include"
INCLUDEPATH += "D:/halcon_zhengban/include/halconcpp"
#INCLUDEPATH += "F:/Halcon/HALCON-12.0/include/cpp"   #这句配置是错误的，不能编译成功
#libs
#QMAKE_LIBDIR     += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
#LIBPATH += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
LIBPATH     += "D:/halcon/lib/x64-win64"
unix:LIBS   += -lhalconcpp -lhalcon -ldl -lpthread
win32:LIBS  += halconcpp.lib halcon.lib

RESOURCES +=
