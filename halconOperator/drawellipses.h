#ifndef DRAWELLIPSES_H
#define DRAWELLIPSES_H
#include"h_operators.h"
#include <QWidget>

namespace Ui {
class DrawEllipses;
}

class DrawEllipses : public QWidget,public h_operators
{
    Q_OBJECT

public:
    explicit DrawEllipses(QWidget *parent = nullptr);
    ~DrawEllipses();

    DrawEllipses();
    DrawEllipses(HalconCpp::HObject *m_region,HalconCpp::HTuple hv_WindowHandle,HalconCpp::HTuple hv_Row,
                HalconCpp::HTuple hv_Column, HalconCpp::HTuple hv_Phi,
                HalconCpp::HTuple hv_Radius1,HalconCpp::HTuple  hv_Radius2, bool m_isDraw);
    virtual void Myoperators();

    HalconCpp::HObject *m_region;
    HalconCpp::HTuple hv_Row;
    HalconCpp::HTuple hv_Column;
    HalconCpp::HTuple hv_Phi;
    //前半轴
    HalconCpp::HTuple hv_Radius1;
    //半轴
    HalconCpp::HTuple  hv_Radius2;
    bool m_isDraw;


    HalconCpp::HTuple hv_WindowHandle;
    //参数控制

private:
    Ui::DrawEllipses *ui;
};

#endif // DRAWELLIPSES_H
