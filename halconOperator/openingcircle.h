#ifndef OPENINGCIRCLE_H
#define OPENINGCIRCLE_H
#include<QLineEdit>
#include <QWidget>
#include"h_operators.h"
#include<QLabel>
namespace Ui {
class OpeningCircle;
}

class OpeningCircle : public QWidget,public h_operators
{
    Q_OBJECT

public:
    explicit OpeningCircle(QWidget *parent = nullptr);
    ~OpeningCircle();


    OpeningCircle(HalconCpp:: HObject *ho_Region);
    void Myoperators();
    void setMessage(QVector<HalconCpp::HTuple>& v,bool isRead);
    void setMessage(QVector<HalconCpp::HObject*> &v);
    QMap<QString,HalconCpp::HObject*>& getObj();
    QMap<QString,QVector<DateClass>*>& getHtup();

    QMap<QString,HalconCpp::HObject*> hObjects;
    QMap<QString,QVector<DateClass>*> hTupleM;
    QVector<DateClass> hTuples;


    // 输入
    HalconCpp::HTuple radius=3.5;
    HalconCpp:: HObject *ho_Region;

    //输出
    HalconCpp:: HObject ho_RegionOpening;

    //存档
   void  archive(QString path);

   //ui界面
   void ui_openingCircle();
   QLabel *label;
   QLineEdit *edit;

private:
    Ui::OpeningCircle *ui;
};

#endif // OPENINGCIRCLE_H
