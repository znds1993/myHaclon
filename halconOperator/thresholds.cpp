#include "thresholds.h"
#include "ui_thresholds.h"
#include"QDebug"
Thresholds::Thresholds(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Thresholds)
{
    ui->setupUi(this);

}

Thresholds::~Thresholds()
{
    delete ui;
}

Thresholds::Thresholds(HalconCpp::HObject *m_referImage):m_referImage(m_referImage)
{

}

void Thresholds::Myoperators()
{
    try {
       HalconCpp::Threshold(*m_referImage, &ho_Region, lower,up);
        if (HalconCpp::HDevWindowStack::IsOpen())
        {
            ClearWindow(HalconCpp::HDevWindowStack::GetActive());
            HalconCpp::DispObj(ho_Region, HalconCpp::HDevWindowStack::GetActive());
        }
    } catch (HalconCpp::HException& e) {

    }
}

void Thresholds::setMessage(QVector<HalconCpp::HTuple>& v,bool isRead)
{
    if(isRead){
        QString s1= v[1].S().Text();
        double d1=s1.toDouble();

        QString s2= v[0].S().Text();
        double d2=s2.toDouble();

        this->up=d1;
        this->lower=d2;
    }else{
        this->up=v[0];
        this->lower=v[1];
    }
}

void Thresholds::setMessage(QVector<HalconCpp::HObject *> &v)
{
    //this->m_referImage=v[0];
}

QMap<QString, QVector<DateClass>*> &Thresholds::getHtup()
{
    this->htupV.clear();
    this->htupV.push_back(DateClass("lower",&lower));
    this->htupV.push_back(DateClass("up",&up));
    this->htupM.insert("thresholds",&htupV);
    return this->htupM;
}


QMap<QString, HalconCpp::HObject *>& Thresholds::getObj()
{
    m=new QMap<QString, HalconCpp::HObject *>;
    m->insert("ho_Region",&ho_Region);
    return *m;
}

void Thresholds::ui_thresholds()
{
    this->label_UP=new  QLabel("上限",this);
    this->label_lower=new  QLabel("下限",this);


    //QSlider设置上限
    this->slider_up =new QSlider(Qt::Horizontal,this);
    this->slider_up->setMaximum(255);
    this->slider_up->setMinimum(0);
    this->slider_up->setValue(255);//默认值
    //QSlider设置下限
    this->slider_lower =new QSlider(Qt::Horizontal,this);
    this->slider_lower->setMaximum(255);
    this->slider_lower->setMinimum(0);
    this->slider_lower->setValue(0);
    //QSpinBox上限
    this->spinBox_UP=new QSpinBox(this);
    this->spinBox_UP->setRange(0, 255);  // 变化范围
    this->spinBox_UP->setValue(255);//默认值
    //QSpinBox下限
    this->spinBox_lower=new QSpinBox(this);
    this->spinBox_lower->setRange(0, 255);  // 变化范围
    this->spinBox_lower->setValue(0);//默认值
    QGridLayout * grid=new QGridLayout(this);
    grid->addWidget(label_UP,0,0);
    grid->addWidget(spinBox_UP,0,1);
    grid->addWidget(slider_up,0,2);
    grid->addWidget(label_lower,1,0);
    grid->addWidget(spinBox_lower,1,1);
    grid->addWidget(slider_lower,1,2);
    this->setLayout(grid);

    void(QSpinBox::*spi)(int)=&QSpinBox::valueChanged;
    connect(spinBox_UP,spi,slider_up,&QSlider::setValue);
    connect(slider_up,&QSlider::valueChanged,spinBox_UP,[=](int value){
        spinBox_UP->setValue (value);
        this->up= HalconCpp::HTuple(value);
        emit dynamic();
    });

    connect(spinBox_lower,spi,slider_lower,&QSlider::setValue);
    connect(slider_lower,&QSlider::valueChanged,spinBox_lower,[=](int value){
        spinBox_lower->setValue (value);
        this->lower=HalconCpp::HTuple(value);
        emit dynamic();
    });
}

void Thresholds::archive(QString path)
{

    QMultiMap<QString ,QVector<  HalconCpp::HTuple >*> *dc=new  QMultiMap<QString ,QVector<  HalconCpp::HTuple >*>;
    QVector<HalconCpp::HTuple >* v=new QVector<HalconCpp::HTuple >;
    //最小值
    v->append(this->lower);
    //最大值
    v->append(this->up);

    dc->insert("5.thresholds",v);
    h_operators::write(dc,path);
}
