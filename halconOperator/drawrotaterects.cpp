#include "drawrotaterects.h"
#include "ui_drawrotaterects.h"

DrawRotateRects::DrawRotateRects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawRotateRects)
{
    ui->setupUi(this);
}

DrawRotateRects::~DrawRotateRects()
{
    delete ui;
}

DrawRotateRects::DrawRotateRects(HalconCpp::HObject &m_region,HalconCpp::HTuple hv_WindowHandle,
                               HalconCpp::HTuple &hv_Row,  HalconCpp::HTuple  &hv_Column,  HalconCpp::HTuple  &hv_Phi,
                               HalconCpp::HTuple &hv_Length1,  HalconCpp::HTuple  &hv_Length2)
{
    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "blue");
    DrawRectangle2(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Phi, &hv_Length1, &hv_Length2);
    GenRectangle2(&m_region, hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2);
    HalconCpp::DispRectangle2(hv_WindowHandle, hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2);
}
