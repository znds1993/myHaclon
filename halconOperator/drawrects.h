#ifndef DRAWRECTS_H
#define DRAWRECTS_H
#include"h_operators.h"
#include <QWidget>

namespace Ui {
class DrawRects;
}

class DrawRects : public QWidget,public h_operators
{
    Q_OBJECT

public:
    explicit DrawRects(QWidget *parent = nullptr);
    ~DrawRects();

    DrawRects(HalconCpp::HObject &m_region, HalconCpp::HTuple hv_Row1, HalconCpp::HTuple hv_Column1
              ,HalconCpp::HTuple hv_Row2,HalconCpp::HTuple hv_Column2,HalconCpp::HTuple hv_WindowHandle);
    HalconCpp::HTuple hv_Row1, hv_Column1;
    HalconCpp::HTuple hv_Row2, hv_Column2,hv_WindowHandle;
    HalconCpp::HObject *m_region;



private:
    Ui::DrawRects *ui;
};

#endif // DRAWRECTS_H
