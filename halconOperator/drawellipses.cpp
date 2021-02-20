#include "drawellipses.h"
#include "ui_drawellipses.h"

DrawEllipses::DrawEllipses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawEllipses)
{
    ui->setupUi(this);
}

DrawEllipses::~DrawEllipses()
{
    delete ui;
}

DrawEllipses::DrawEllipses()
{

}

DrawEllipses::DrawEllipses(HalconCpp::HObject *m_region, HalconCpp::HTuple hv_WindowHandle, HalconCpp::HTuple hv_Row, HalconCpp::HTuple hv_Column,
                         HalconCpp::HTuple hv_Phi, HalconCpp::HTuple hv_Radius1, HalconCpp::HTuple hv_Radius2, bool m_isDraw)
    :m_region(m_region),hv_WindowHandle(hv_WindowHandle),hv_Row(hv_Row),hv_Column(hv_Column),hv_Phi(hv_Phi),
      hv_Radius1(hv_Radius1),hv_Radius2(hv_Radius2),m_isDraw(m_isDraw)
{

}

void DrawEllipses::Myoperators()
{
//      m_isDraw=true;
//    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "yellow");
//    HalconCpp::DrawEllipse(hv_WindowHandle, hv_Row, hv_Column, hv_Phi, hv_Radius1, hv_Radius2);
//    HalconCpp::GenEllipse(m_region, hv_Row, hv_Column, hv_Phi, hv_Radius1, hv_Radius2);
//    HalconCpp::DispEllipse(hv_WindowHandle, hv_Row, *hv_Column, *hv_Phi, *hv_Radius1, *hv_Radius2);
//     m_isDraw=false;
}
