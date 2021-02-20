#include "openingcircle.h"
#include "ui_openingcircle.h"

OpeningCircle::OpeningCircle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpeningCircle)
{
    ui->setupUi(this);
}

OpeningCircle::~OpeningCircle()
{
    delete ui;
}

OpeningCircle::OpeningCircle(HalconCpp::HObject *ho_Region):ho_Region(ho_Region)
{

}

void OpeningCircle::Myoperators()
{
    HalconCpp::OpeningCircle(*ho_Region, &ho_RegionOpening, radius);
}

void OpeningCircle::setMessage(QVector<HalconCpp::HTuple> &v, bool isRead)
{
    if(isRead){
        QString s1= v[0].S().Text();
        double d1=s1.toDouble();

        this->radius=d1;
    }else{
        this->radius=v[0];
   }
}

void OpeningCircle::setMessage(QVector<HalconCpp::HObject *> &v)
{

}

QMap<QString, HalconCpp::HObject *> &OpeningCircle::getObj()
{
    this->hObjects.insert("ho_RegionOpening",&ho_RegionOpening);
    return this->hObjects;
}

QMap<QString, QVector<DateClass> *> &OpeningCircle::getHtup()
{
    return this->hTupleM;
}

void OpeningCircle::archive(QString path)
{
    QMultiMap<QString ,QVector<  HalconCpp::HTuple >*> *dc=new  QMultiMap<QString ,QVector<  HalconCpp::HTuple >*>;
    QVector<HalconCpp::HTuple >* v=new QVector<HalconCpp::HTuple >;
    //腐蚀系数
    v->append(this->radius);

    dc->insert("6.OpeningCircle",v);
    h_operators::write(dc,path);
}

void OpeningCircle::ui_openingCircle()
{
    QGridLayout * grid=new QGridLayout(this);
    label=new QLabel("腐蚀系数: ",this);
    edit=new QLineEdit(this);
    grid->addWidget(label,0,0);
    grid->addWidget(edit,0,1);
    this->setLayout(grid);
    connect(this->edit,&QLineEdit::textEdited,this,[=](QString text){
         this->radius=text.toDouble();
    });
}
