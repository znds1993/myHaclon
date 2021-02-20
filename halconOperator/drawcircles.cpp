#include "drawcircles.h"
#include "ui_drawcircles.h"
#include"QDebug"
#include"QString"
DrawCircles::DrawCircles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawCircles)
{
    ui->setupUi(this);

}

DrawCircles::~DrawCircles()
{
    delete ui;
}
DrawCircles::DrawCircles( HalconCpp::HTuple hv_WindowHandle, HalconCpp:: HObject *m_referImage,bool * m_isDraw)
    :hv_WindowHandle(hv_WindowHandle),m_referImage(m_referImage),m_isDraw(m_isDraw)
{

}
void DrawCircles::Myoperators()
{
    try {
        HalconCpp::HObject m_region;
        //判断HTuple是否为空
        HalconCpp::HTuple hv_Length;
        HalconCpp::TupleLength(hv_Row, &hv_Length);
        if (hv_Length.I() == 0)
        {
            *m_isDraw=true;
            HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(),color);
            HalconCpp::DrawCircle(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Radius);
            HalconCpp::GenCircle(&m_region, hv_Row, hv_Column, hv_Radius);
            HalconCpp::DispCircle(hv_WindowHandle, hv_Row, hv_Column, hv_Radius);
            HalconCpp::ReduceDomain(*m_referImage, m_region, &ho_ImageReduced);
            *m_isDraw=false;
        }else{
            HalconCpp::GenCircle(&m_region, hv_Row, hv_Column, hv_Radius);
            HalconCpp::DispCircle(hv_WindowHandle, hv_Row, hv_Column, hv_Radius);
            HalconCpp::ReduceDomain(*m_referImage, m_region, &ho_ImageReduced);

        }
    } catch (HalconCpp::HException& e) {

    }
}

void DrawCircles::setMessage(QVector<HalconCpp::HTuple> &v,bool isRead)
{
    //转double;
    if(isRead){
        this->color=v[0];

        QString s1= v[1].S().Text();
        double d1=s1.toDouble();

        QString s2= v[2].S().Text();
        double d2=s2.toDouble();

        QString s3= v[3].S().Text();
        double d3=s3.toDouble();


        this->hv_Row=HalconCpp::HTuple(d1);
        this->hv_Column=HalconCpp::HTuple(d2);
        this->hv_Radius=HalconCpp::HTuple(d3);
    }else{
        this->color=v[0];
    }
}
void DrawCircles::setMessage(QVector<HalconCpp::HObject*> &v){
    this->m_referImage=v[0];
}
QMap<QString,HalconCpp::HObject*>& DrawCircles::getObj(){
    this->hObjects.insert("ho_ImageReduced",&ho_ImageReduced);
    return  this->hObjects;
}

QMap<QString,QVector<DateClass>*>& DrawCircles::getHtup()
{
    this->hTupleM.clear();
    this->hTuples.push_back(DateClass("color",&this->color));
    this->hTuples.push_back(DateClass("Row",&this->hv_Row));
    this->hTuples.push_back(DateClass("Column",&this->hv_Column));
    this->hTuples.push_back(DateClass("Radius",&this->hv_Radius));
    this->hTupleM.insert("1.circle",&this->hTuples);
    return this->hTupleM;
}

//设置ROI的原色
void DrawCircles::ui_creator()
{
    label=new QLabel("颜色:",this);
    comboBox=new QComboBox(this);
    comboBox->addItem("black");
    comboBox->addItem("white");
    comboBox->addItem("green");
    comboBox->addItem("blue");
    QHBoxLayout * vb=new QHBoxLayout(this);
    vb->addWidget(label);
    vb->addWidget(comboBox);
    this->setLayout(vb);
    void (QComboBox::* box) (const QString&)=&QComboBox::activated;
    connect(this->comboBox,box,this,[=](const QString &text){
        this->color=text.toLatin1().data();
    });
}

void DrawCircles::archive(QString path)
{
    QMultiMap<QString ,QVector<  HalconCpp::HTuple >*> *dc=new  QMultiMap<QString ,QVector<  HalconCpp::HTuple >*>;
    QVector<HalconCpp::HTuple >* v=new QVector<HalconCpp::HTuple >;
    //颜色
    v->append(this->color);
    //行
    v->append(hv_Row);
    //列
    v->append(hv_Column);
    //半径
    v->append(hv_Radius);
    dc->insert("1.circle",v);
    h_operators::write(dc,path);
    this->hv_Row.Clear();
}
