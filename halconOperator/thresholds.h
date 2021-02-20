#ifndef THRESHOLDS_H
#define THRESHOLDS_H
#include"h_operators.h"
#include <QWidget>
#include<QLabel>
#include<QSlider>
#include<QSpinBox>
#include<QMap>
namespace Ui {
class Thresholds;
}

class Thresholds : public QWidget,public h_operators
{
    Q_OBJECT
public:
    explicit Thresholds(QWidget *parent = nullptr);
    ~Thresholds();
    Thresholds(HalconCpp::HObject *m_referImage);
    void Myoperators();
    void setMessage(QVector<HalconCpp::HTuple>& v,bool isRead);
    void setMessage(QVector<HalconCpp::HObject*> &v);
    QMap<QString,QVector<DateClass>*>& getHtup();
    QMap<QString,HalconCpp::HObject*>& getObj();

    HalconCpp::HObject *m_referImage;
    HalconCpp::HObject ho_Region;
    HalconCpp::HTuple lower=21;
    HalconCpp::HTuple up=184;
    QMap<QString, HalconCpp::HObject *> *m;
    //ui界面
    void ui_thresholds();
    QLabel * label_UP;
    QSpinBox * spinBox_lower;
    QSpinBox * spinBox_UP;
    QLabel * label_lower;
    QSlider * slider_up;
    QSlider * slider_lower;


    QVector<DateClass> htupV;
    QMap<QString, QVector<DateClass>*> htupM;

    void  archive(QString path);
    //是否是读挡
    bool isread;
signals:

    void dynamic();
private:

    Ui::Thresholds *ui;

};

#endif // THRESHOLDS_H
