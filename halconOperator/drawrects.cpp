#include "drawrects.h"
#include "ui_drawrects.h"

DrawRects::DrawRects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawRects)
{
    ui->setupUi(this);
}

DrawRects::~DrawRects()
{
    delete ui;
}

DrawRects::DrawRects(HalconCpp::HObject &m_region, HalconCpp::HTuple hv_Row1, HalconCpp::HTuple hv_Column1
                   ,HalconCpp::HTuple hv_Row2,HalconCpp::HTuple hv_Column2,HalconCpp::HTuple hv_WindowHandle)
{
    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "green");
    HalconCpp::DrawRectangle1(hv_WindowHandle, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);
    HalconCpp::GenRectangle1(&m_region, hv_Row1, hv_Column1, hv_Row2, hv_Column2);
    HalconCpp::DispRectangle1(hv_WindowHandle, hv_Row1, hv_Column1, hv_Row2, hv_Column2);

}
