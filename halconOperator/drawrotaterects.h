#ifndef DRAWROTATERECTS_H
#define DRAWROTATERECTS_H
#include"h_operators.h"
#include <QWidget>

namespace Ui {
class DrawRotateRects;
}

class DrawRotateRects : public QWidget,public h_operators
{
    Q_OBJECT

public:
    explicit DrawRotateRects(QWidget *parent = nullptr);
    ~DrawRotateRects();

public:
    DrawRotateRects(HalconCpp::HObject &m_region,HalconCpp::HTuple hv_WindowHandle,
                   HalconCpp::HTuple &hv_Row,  HalconCpp::HTuple  &hv_Column,  HalconCpp::HTuple  &hv_Phi,
                   HalconCpp::HTuple &hv_Length1,  HalconCpp::HTuple  &hv_Length2);
private:
    Ui::DrawRotateRects *ui;
};

#endif // DRAWROTATERECTS_H
