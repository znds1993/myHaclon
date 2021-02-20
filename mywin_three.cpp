#include "mywin_three.h"
#include "ui_mywin_three.h"
#include"QDebug"
#include<QMouseEvent>
#include<QList>
#include<QHeaderView>
Mywin_three::Mywin_three(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mywin_three)
{
    ui->setupUi(this);
    treeWidget=new QTreeWidget();
   treeWidget->header()->setVisible(false);
    ui->horizontalLayout->addWidget(treeWidget);
    //创建菜单
    meun = new QMenu(treeWidget);
    del = new QAction(" 删除", this);
    meun->addAction(del);

    connect(del,&QAction::triggered,this,[=](){
        QTreeWidgetItem* item= treeWidget->selectedItems()[0];
        int count = item->childCount();
        for(int i=0; i<count; i++)
        {
            QTreeWidgetItem *childItem = item->child(0);//删除子节点
        }
        delete item;
    });
    connect(this->treeWidget,&QTreeWidget::itemPressed,[=](QTreeWidgetItem *item, int column){
        if(!item->parent()&&QGuiApplication::mouseButtons() & Qt::RightButton){
            meun->exec(QCursor::pos());
        }
    });
}

Mywin_three::~Mywin_three()
{
    delete ui;
}

void Mywin_three::addDate(QMap<QString,QVector<DateClass>*> &m)
{ 
    QMap<QString,QVector<DateClass>*>::iterator it=(&m)->begin();
    QTreeWidgetItem * item=new QTreeWidgetItem;
    item->setText(0,it.key());

    QVector<DateClass>* date=it.value();

    //判断是否是重复执行同一个算子
    for (QVector<DateClass>::iterator d_it=date->begin();d_it!=date->end();d_it++) {
        QString date;
        try {
            date=d_it->dates[0].S();
        } catch (HalconCpp::HException& e) {
            date= QString::number(d_it->dates[0].D(),5,5);
        }
        for (QMap<QTreeWidgetItem *,DateClass>::iterator ve=(&hV)->begin();ve!=(&hV)->end();ve++) {
            if(ve.value().dates==d_it->dates){
                isAgain=true;
                ve.key()->setText(0,ve.value().parameter_name+" :  "+date);
            }
        }
    }
    if(isAgain){
        isAgain=false;
        return;
    }
    for (QVector<DateClass>::iterator d_it=date->begin();d_it!=date->end();d_it++) {
        QString date;
        try {
            date=d_it->dates[0].S();
        } catch (HalconCpp::HException& e) {
            date= QString::number(d_it->dates[0].D(),5,5);
        }
        QTreeWidgetItem * item_child=new QTreeWidgetItem(QStringList()<<d_it->parameter_name+"  :  "+date);
        item->addChild(item_child);
        this->treeWidget->addTopLevelItem(item);
        //保存每个参数的地址和树的项
        hV.insert(item_child,*d_it);
    }
}


