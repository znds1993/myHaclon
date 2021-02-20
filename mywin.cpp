#include "mywin.h"
#include "ui_mywin.h"
#include"QMouseEvent"
#include"QDialog"
#include"QDebug"
#include"QAction"
#include"QVBoxLayout"
#include"QMenu"
MyWin::MyWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWin)
{
    ui->setupUi(this);
}

MyWin::~MyWin()
{
    delete ui;
}

void MyWin::AddImage(const HalconCpp::HObject& image) {
    m_thread.c_Operator.m_referImage = image;
    InitData();
    InitUi();
    createMenu();
    m_isfirst = false;
}
void MyWin::InitData(){
    mouseLeftPressed = false;
    windowWidth  = this->width();
    windowHeight = this->height();
    try {
        HalconCpp::GetImageSize(m_thread.c_Operator.m_referImage, &m_thread.c_Operator.imageWidth, &m_thread.c_Operator.imageHeight);
    } catch (HalconCpp::HException& e) {

    }
    ImgRow1  = 0;
    ImgCol1  = 0;
    ImgRow2  =m_thread.c_Operator.imageHeight.D() - 1;
    ImgCol2  = m_thread.c_Operator.imageWidth.D() - 1;
    m_thread.c_Operator.m_isDraw = false;
}
void MyWin:: binding(){
    //绑定窗口
    HWND hwndID = (HWND)this->winId();
    HalconCpp::SetWindowAttr("background_color","black");
    HalconCpp:: OpenWindow(this->rect().top(),this->rect().left(),this->rect().width(),this->rect().height(),
                           (Hlong)this->winId(),"visible","",&m_thread.c_Operator.hv_WindowHandle);
}
void MyWin::InitUi(){
    if (m_isfirst) {
        HalconCpp::SetSystem("width", 5000);
        HalconCpp::SetSystem("height", 5000);

        HalconCpp::SetWindowAttr("background_color", "black");
        binding();
        HalconCpp::HDevWindowStack::Push(m_thread.c_Operator.hv_WindowHandle);

        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "green");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetDraw(m_thread.c_Operator.hv_WindowHandle, "margin");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetLineWidth(m_thread.c_Operator.hv_WindowHandle, 2);
        setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);
    }

    if (HalconCpp::HDevWindowStack::IsOpen()){
        HalconCpp::DispObj(m_thread.c_Operator.m_referImage, HalconCpp::HDevWindowStack::GetActive());
    }
}
void MyWin::setImagePart(int r1, int c1, int r2, int c2) {
    ImgRow1 = r1;
    ImgCol1 = c1;
    ImgRow2 = r2;
    ImgCol2 = c2;
    //设置移动后图像的位置
    HalconCpp::SetPart(m_thread.c_Operator.hv_WindowHandle,(int)ImgRow1, (int)ImgCol1, (int)ImgRow2, (int)ImgCol2);
}
void MyWin::RunImage(const HalconCpp::HObject& image) {
    m_thread.c_Operator.m_referImage = image;
    HalconCpp::DispObj(m_thread.c_Operator.m_referImage, HalconCpp::HDevWindowStack::GetActive());
    Blob();
}
void MyWin::mouseMoveEvent(QMouseEvent* event){

    if (mouseLeftPressed && ! m_thread.c_Operator.m_isDraw) {
        int i=event->x();
        int i2=event->y();
        if (i!=startX || i2!=startY) {
            moveImage(i - startX, i2 - startY);
            startX = i;
            startY =i2;
        }
    }
}
void MyWin:: mousePressEvent(QMouseEvent* event){
    if (Qt::LeftButton == event->buttons() && ! m_thread.c_Operator.m_isDraw) {
        mouseLeftPressed = true;
        startX           = event->x();
        startY           = event->y();
    }

}
void MyWin::mouseReleaseEvent(QMouseEvent* event){
    mouseLeftPressed = false;
}
void MyWin::wheelEvent(QWheelEvent* event){
    double scale = 0;
    QPoint numDegrees = event->angleDelta() / 8;
    if (!numDegrees.isNull()) {
        QPoint numSteps = numDegrees / 15;
        if(numSteps.y()<0){
            scale = 0.9 * 1;
        }else{
            scale = 1 / (0.9 * 1);
        }
    }
    zoomImage(event->x(), event->y(), scale);
}

void MyWin::contextMenuEvent(QContextMenuEvent *e)
{
    if(!isOpenImage){
        menu->clear();
        menu->addAction(a1);
        menu->addAction(a2);
        menu->addAction(a3);
        menu->addMenu(menu1);
        menu->exec(QCursor::pos());
        e->accept();
    }

}
void MyWin::zoomImage(double x, double y, double scale) {
    double xInImage = 0, yInImage = 0;
    xInImage = ImgCol1 + x / windowWidth * (ImgCol2 - ImgCol1);
    yInImage = ImgRow1 + y / windowHeight * (ImgRow2 - ImgRow1);

    double lengthC, lengthR;
    double pencentC, pencentR;

    pencentC =  (ImgCol2 == ImgCol1) ? 0 : (xInImage - ImgCol1) / (ImgCol2 - ImgCol1);
    pencentR =  (ImgRow2 == ImgRow1) ? 0 : (yInImage - ImgRow1) / (ImgRow2 - ImgRow1);

    lengthC = (ImgCol2 - ImgCol1) * scale;
    lengthR = (ImgRow2 - ImgRow1) * scale;

    double ImgCol1Tmp = xInImage - lengthC * pencentC;
    double ImgCol2Tmp = xInImage + lengthC * (1 - pencentC);
    double ImgRow1Tmp = yInImage - lengthR * pencentR;
    double ImgRow2Tmp = yInImage + lengthR * (1 - pencentR);
    if (ImgCol1Tmp == ImgCol2Tmp) {
        ImgCol1Tmp = xInImage - 0.5;
        ImgCol2Tmp = xInImage + 0.5;

        ImgCol1 = ImgCol1Tmp;
        ImgCol2 = ImgCol2Tmp;
    }

    if (ImgRow1 == ImgRow2) {
        ImgRow1Tmp = yInImage - 0.5;
        ImgRow2Tmp = yInImage + 0.5;
        ImgRow1    = ImgRow1Tmp;
        ImgRow2    = ImgRow2Tmp;
    }

    double T = 30000;
    if (fabs(ImgCol1Tmp) < T && fabs(ImgCol2Tmp) < T && fabs(ImgRow1Tmp) < T && fabs(ImgRow2Tmp) < T) {
        ImgCol1 = ImgCol1Tmp;
        ImgCol2 = ImgCol2Tmp;
        ImgRow1 = ImgRow1Tmp;
        ImgRow2 = ImgRow2Tmp;

        setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);
        UpdateImage();
    }
}

void MyWin::createMenu()
{
    //创建菜单栏
    isOpenImage=false;
    menu=new QMenu(this);
    a1=new QAction("显示原图",this);
    a2=new QAction("保存图片",this);
    a3=new QAction("更新窗口",this);
    QAction *a4=new QAction("gradation histogram",this);
    QAction *a5=new QAction("Feature histogram",this);
    menu1=new QMenu("工具",this);
    menu1->addAction(a4);
    menu1->addAction(a5);
    connect(a1,&QAction::triggered,this,[=](){
        emit select_Old_image();
    });
    connect(a2,&QAction::triggered,this,[=](){
        emit save_image();
    });
}
void MyWin::moveImage(double motionX, double motionY) {
    double deltaR = motionY / windowHeight * (ImgRow2 - ImgRow1);
    double deltaC = motionX / windowWidth * (ImgCol2 - ImgCol1);
    ImgRow1 -= deltaR;
    ImgRow2 -= deltaR;

    ImgCol1 -= deltaC;
    ImgCol2 -= deltaC;
    setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);
    UpdateImage();
}
void MyWin::UpdateImage() {
    //先清除原窗口的内容
    HalconCpp::ClearWindow(m_thread.c_Operator.hv_WindowHandle);
    //再显示修改后的图像
    DispObj(m_thread.c_Operator.m_referImage, m_thread.c_Operator.hv_WindowHandle);
}
void MyWin::Blob(){
    try {
        // Local iconic variables
        HalconCpp::HObject ho_ImageReduced, ho_ImageMean;
        HalconCpp::HObject ho_Region, ho_ConnectedRegions, ho_SelectedRegions;

        // Local control variables
        HalconCpp::HTuple hv_Area, hv_Row, hv_Column;

        // HalconCpp::ReduceDomain(m_thread.c_Operator.m_referImage,m_thread.c_Operator. m_region, &ho_ImageReduced);

        //    HalconCpp::Threshold(ho_ImageReduced, &ho_Region, 0, 200);

        MeanImage(ho_ImageReduced, &ho_ImageMean, 9, 9);
        DynThreshold(m_thread.c_Operator.m_referImage, ho_ImageMean, &ho_Region, 5, "light");

        HalconCpp::Connection(ho_Region, &ho_ConnectedRegions);

        HalconCpp::SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 150, 99999);

        HalconCpp::AreaCenter(ho_SelectedRegions, &hv_Area, &hv_Row, &hv_Column);

        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::DispObj(ho_SelectedRegions, HalconCpp::HDevWindowStack::GetActive());

        int test = hv_Area.Length();
        int ddd  = 0;

        //    HalconCpp::SobelAmp(m_referImage, &ho_ImageReduced, "sum_abs", 3);
        //    HalconCpp::DispObj(ho_ImageReduced, HalconCpp::HDevWindowStack::GetActive()
    } catch (HalconCpp::HException& e) {

    }
}
