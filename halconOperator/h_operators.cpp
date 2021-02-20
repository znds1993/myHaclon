#include "h_operators.h"
#include"QDebug"
//h_operators::h_operators(QWidget *parent) : QWidget(parent)
//{

//}
h_operators::h_operators(){

}

void h_operators::Myoperators()
{

}

void h_operators::setMessage(QVector<HalconCpp::HTuple> &v,bool isRead)
{

}

void h_operators::setMessage(QVector<HalconCpp::HObject *>& v)
{

}

void h_operators::archive(QString path)
{

}

void h_operators::write(QMultiMap<QString ,QVector<HalconCpp::HTuple >*> *map,QString fileName)
{
    ofstream ofs;
    ofs.open(fileName.toLatin1(),ios::out|ios::app);
    for(QMultiMap<QString,QVector<HalconCpp::HTuple >*>::iterator it=map->begin();it!=map->end();it++) {
        QString operatorsId=it.key();
        ofs<<operatorsId.toLatin1().data()<<"-";
        QVector<  HalconCpp::HTuple >* parameter=it.value();
        for (QVector<  HalconCpp::HTuple >::iterator v=parameter->begin();v!=parameter->end();v++) {
            try {
                ofs<<(*v)[0].S()<<"-";
            } catch (HalconCpp::HException& e) {
                ofs<<(*v)[0].D()<<"-";
            }
        }
        ofs<<endl;
    }
    ofs.close();
}

QMultiMap<QString, QVector<HalconCpp::HTuple>*>* h_operators::read(QString fileName)
{
    QMultiMap<QString ,QVector<HalconCpp::HTuple >*> *map=new QMultiMap<QString ,QVector<HalconCpp::HTuple >*> ;
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QStringList list;
    QVector<HalconCpp::HTuple >* v =new QVector<HalconCpp::HTuple>;;

    while(!file.atEnd()){
        v=new QVector<HalconCpp::HTuple>;
        list=QString(file.readLine()).split("-");
        for (int i=1;i<list.size()-1;i++) {
            v->push_back(list[i].toLatin1().data());
        }
           map->insert(list[0],v);
    }

    file.close();
    return map;
}

QMap<QString,HalconCpp::HObject*>& h_operators::getObj()
{
    QMap<QString,HalconCpp::HObject*> s;
    return s ;
}

QMap<QString,QVector<DateClass>*>& h_operators::getHtup()
{
    QMap<QString,QVector<DateClass>*> s;
    return s;
}



DateClass::DateClass()
{

}

DateClass::DateClass(QString parameter_name, HalconCpp::HTuple* dates)
    :parameter_name(parameter_name),dates(dates)
{

}
