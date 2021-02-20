#ifndef H_OPERATORS_H
#define H_OPERATORS_H
#include"HalconCpp.h"
#include <QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include <stdarg.h>
#include <stdio.h>
#include"QVector"
#include <fstream>
#include<QMap>
#include<QDir>
#include<QString>
#include<QStringList>
#include<QMultiMap>
using namespace std;

struct A
{
    A(int) { }
    operator bool() const { return true; }
};
class DateClass{
public:
    QString parameter_name;
    HalconCpp::HTuple* dates;
    DateClass();
    DateClass(QString parameter_name,HalconCpp::HTuple* dates);

};
class h_operators
{
    // Q_OBJECT
public:
    //explicit h_operators(QWidget *parent = nullptr);
    h_operators();

    //启动算子
    virtual void Myoperators();

    //设置参数（ui界面获取）
    virtual void setMessage(QVector<HalconCpp::HTuple>& v,bool isRead);
    virtual void setMessage(QVector<HalconCpp::HObject*>& v);
    //获取算子的Hobject参数
    virtual QMap<QString,HalconCpp::HObject*>& getObj();
    //获取算子Htuple参数
    virtual QMap<QString,QVector<DateClass>*>& getHtup();
    // 存档
    virtual void  archive(QString path);
    //写到文件中
    void write(QMultiMap<QString ,QVector<HalconCpp::HTuple >*> *map,QString fileName);
    //读文件
    QMultiMap<QString ,QVector<HalconCpp::HTuple >*> * read(QString fileName);
signals:

public slots:
};

#endif // H_OPERATORS_H
