#ifndef DRAWCIRCLES_H
#define DRAWCIRCLES_H
#include"h_operators.h"
#include <QWidget>
#include"QLabel"
#include"QComboBox"
#include"QVector"
#include<QMap>
namespace Ui {
class DrawCircles;
}

class DrawCircles : public QWidget,public h_operators
{
    Q_OBJECT

public:
    explicit DrawCircles(QWidget *parent = nullptr);
    ~DrawCircles();

    DrawCircles(HalconCpp::HTuple hv_WindowHandle, HalconCpp:: HObject *m_referImage,bool *m_isDraw);
    void Myoperators();
    void setMessage(QVector<HalconCpp::HTuple>& v,bool isRead);
    void setMessage(QVector<HalconCpp::HObject*> &v);
    QMap<QString,HalconCpp::HObject*>& getObj();
    QMap<QString,QVector<DateClass>*>& getHtup();

    QMap<QString,HalconCpp::HObject*> hObjects;

    QMap<QString,QVector<DateClass>*> hTupleM;
    QVector<DateClass> hTuples;

    //输出
    HalconCpp::HObject ho_ImageReduced;


    //输入
    HalconCpp::HTuple hv_WindowHandle;
    HalconCpp:: HObject *m_referImage;
    bool *  m_isDraw;


    HalconCpp::HTuple hv_Row;
    HalconCpp::HTuple  hv_Column;
    HalconCpp::HTuple hv_Radius;
    HalconCpp::HTuple color="red";
    //ui界面
    void ui_creator();
    QLabel * label;
    QComboBox * comboBox;
    void  archive(QString path);
private slots:


private:
    Ui::DrawCircles *ui;
};

#endif // DRAWCIRCLES_H
