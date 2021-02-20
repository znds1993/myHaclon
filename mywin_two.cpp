#include "mywin_two.h"
#include "ui_mywin_two.h"
#include<QHBoxLayout>
#include<QLabel>
#include"QDebug"
#include"QAction"
#include"QDir"
#include"QFileDialog"
#include"QMessageBox"
#include"QToolButton"
#include"QIcon"
#include"QSize"
#include"QMouseEvent"
#include<QFile>
Mywin_two::Mywin_two( MyWin *wi,QWidget *parent) :
    wi(wi),
    QWidget(parent),
    ui(new Ui::Mywin_two)
{
    ui->setupUi(this);

    //创建窗口
    wi_beas=new QWidget();

    // 按钮布局
    ql_son= new QHBoxLayout (this);

    wi_beas->setLayout(ql_son);
    //添加窗口到滚动条
    ui->scrollArea->setWidget(wi_beas);


    //创建窗口2
    wi_show=new QWidget;
    show_son=new QHBoxLayout(this);
    // 按钮布局
    wi_show->setLayout(show_son);
    //添加滚动条到栈控件
    ui->scrollArea_2->setWidget(wi_show);
    //默认显示
    ui->stackedWidget->setCurrentIndex(0);
}

Mywin_two::~Mywin_two()
{
    delete ui;
}

void Mywin_two::addObject(HalconCpp::HObject obj,MyWin *win)
{
    QDir dir;
    //创建文件夹
    dir.cd("./myHalconImage");
    if(!dir.exists("myHalconImage"))//判断需要创建的文件夹是否存在
    {
        dir.mkdir("myHalconImage"); //创建文件夹
    }
    //根据保存的图片顺序命名文件名
    fileName="./myHalconImage/"+QString::number(++coutFile)+".png";
    //写入文件
    HalconCpp:: WriteImage(obj, "png", 0,(HalconCpp::HTuple)fileName.toLatin1().data());

    label=new QLabel(this);
    QPixmap p(fileName);
    p=p.scaled(140,140, Qt::KeepAspectRatio);
    label->setPixmap(p);

    ql_son->addWidget(label);

    //创建菜单
    meun = new QMenu(label);
    del = new QAction(" 删除", this);
    meun->addAction(del);

    // 加入路径名，label,del;
    labelArray.insert(fileName,_Laber(label,del));
    connect(del,&QAction::triggered,this,[=](){
        ql_son->removeWidget(label);
        label->setParent(nullptr);
        QFile::remove(fileName);
    });
    //注册 过滤器 事件
    label->installEventFilter(this);

}

void Mywin_two::showImage(QMap<QString,HalconCpp::HObject*>& m,h_operators* h)
{

    //创建文件夹
    QDir dir;
    dir.cd("./myHalconImage_show");
    if(!dir.exists("myHalconImage_show"))//判断需要创建的文件夹是否存在
    {
        dir.mkdir("myHalconImage_show"); //创建文件夹
    }
    for (QMap<QString,HalconCpp::HObject*> ::iterator it=(&m)->begin();it!=(&m)->end();it++) {
        QString file;

        HalconCpp::HObject ho=*it.value();
        //判断是再次否至执行同一个算子
        for(QMap<QToolButton*,_toolButton>::iterator itH=(&m_to)->begin();itH!=(&m_to)->end();itH++){
            if(it.value()==itH.value().objs){
                if(ho.IsInitialized()){
                    try {
                        file="./myHalconImage_show/image.png";
                        HalconCpp:: WriteImage(ho, "png", 0,(HalconCpp::HTuple)file.toLatin1().data());

                    } catch (HalconCpp::HException& e) {
                        HalconCpp::RegionToBin(ho, &ho_BinImage, 255, 0,265,250);
                        file="./myHalconImage_show/region.png";
                        HalconCpp:: WriteImage(ho_BinImage, "png", 0,(HalconCpp::HTuple)file.toLatin1().data());
                    }
                    itH.key()->setIcon(QIcon(file));
                    itH.key()->setIconSize(QSize(100,100));
                    m_to.insert(itH.key(),_toolButton(it.key(),it.value(),clears));
                }
                return;
            }
        }

        too=new QToolButton(this);
        if(ho.IsInitialized()){
            try {
                file="./myHalconImage_show/image.png";
                HalconCpp:: WriteImage(ho, "png", 0,(HalconCpp::HTuple)file.toLatin1().data());

            } catch (HalconCpp::HException& e) {
                HalconCpp::RegionToBin(ho, &ho_BinImage, 255, 0,265,250);
                file="./myHalconImage_show/region.png";
                HalconCpp:: WriteImage(ho_BinImage, "png", 0,(HalconCpp::HTuple)file.toLatin1().data());
            }
            too->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            too->setIcon(QIcon(file));
            too->setIconSize(QSize(100,100));
            too->setText(it.key());
            show_son->addWidget(too);

            //创建菜单
            meuns = new QMenu(too);
            clears = new QAction("清空显示", this);
            meuns->addAction(clears);

            this->m_to.insert(too,_toolButton(it.key(),it.value(),clears));
            connect(clears,&QAction::triggered,this,[=](){
                if (HalconCpp::HDevWindowStack::IsOpen()){
                    ClearWindow(HalconCpp::HDevWindowStack::GetActive());
                }
                for(QMap<QToolButton*,_toolButton>::iterator it=(&m_to)->begin();it!=(&m_to)->end();it++){
                    if(it.key()==too){
                        wi->AddImage(*(it.value().objs));
                    }
                }
            });
        }
    }
    //将控件和算子关联，以便删除控件
     this->dM.insert(too,h);
}

void Mywin_two::readeDocument(QString path)
{
    //读取文件夹
    QDir *dir=new QDir(path);
    QStringList filter;
    QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
    for (int i=0;i<fileInfo->count();i++) {
        QString fileNames=fileInfo->at(i).filePath();
        label=new QLabel(this);
        QPixmap p(fileNames);
        p=p.scaled(140,140, Qt::KeepAspectRatio);
        label->setPixmap(p);
        ql_son->addWidget(label);

        //创建菜单
        meun = new QMenu(label);
        del = new QAction(" 删除", this);
        meun->addAction(del);

        // 加入路径名，label,del;
        labelArray.insert(fileNames,_Laber(label,del));
        connect(del,&QAction::triggered,this,[=](){
            ql_son->removeWidget(label);
            label->setParent(nullptr);
        });
        //注册 过滤器 事件
        label->installEventFilter(this);
    }
}

void Mywin_two::deleOutputImage(h_operators* h)
{
    for (QMap<QToolButton*,h_operators*>::iterator it=dM.begin() ;it!=dM.end();it++) {
        if(h==it.value()){
            show_son->removeWidget(it.key());
             it.key()->setParent(nullptr);

        }
    }
}

void Mywin_two::enterEvent(QEvent *event)
{
    for(QMap<QToolButton*,_toolButton>::iterator it=(&m_to)->begin();it!=(&m_to)->end();it++){
        it.key()->installEventFilter(this);
    }
}

bool Mywin_two::eventFilter(QObject* obj, QEvent *e)
{
    QMouseEvent* ev=static_cast<QMouseEvent*>(e);
    if(ok){
        for (QMap<QString,_Laber>::iterator it=labelArray.begin();it!=labelArray.end();it++) {

            QLabel * la=it.value().la;
            if(la == obj && ev->button() == Qt::LeftButton)
            {
                try {
                    if (it.key() != "") {
                        HalconCpp::HTuple path = (HalconCpp::HTuple)it.key().toLatin1().data();
                        HalconCpp::ReadImage(& wi->m_thread.c_Operator.m_referImage, path);
                        wi->AddImage(wi->m_thread.c_Operator.m_referImage);
                    }

                } catch (HalconCpp::HException& e) {
                    QMessageBox::information(NULL, tr("Tip"), tr("Select image path error!"), QMessageBox::Yes);
                }
                break;
            }else if(la == obj && ev->button() == Qt::RightButton){
                this->del=it.value().act;
                this->label=la;
                this->fileName=it.key();
                //显示菜单
                meun->exec(QCursor::pos());
                break;
            }
        }
    }else{
        for(QMap<QToolButton*,_toolButton>::iterator it=(&m_to)->begin();it!=(&m_to)->end();it++){
            if(it.key()== obj && ev->button() == Qt::LeftButton){
                wi->AddImage(*(it.value().objs));
                break;
            }else if(it.key()== obj && ev->button() == Qt::RightButton){
                this->clears=it.value().qac;
                this->too=it.key();
                //显示菜单
                meuns->exec(QCursor::pos());
                break;
            }
        }
    }
    return  QWidget::eventFilter(obj,e);
}

_Laber::_Laber(QLabel *la, QAction *act):la(la),act(act)
{

}
_toolButton::_toolButton(QString names, HalconCpp::HObject *objs,QAction* qac):names(names),objs(objs),qac(qac)
{

}

void Mywin_two::on_pushButton_clicked()
{
    ok=true;
    ui->stackedWidget->setCurrentIndex(0);
}

void Mywin_two::on_pushButton_2_clicked()
{
    ok=false;
    ui->stackedWidget->setCurrentIndex(1);
}
