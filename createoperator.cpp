#include "createoperator.h"
#include"QDebug"
CreateOperator::CreateOperator()
{

}
h_operators* CreateOperator::createOperator(int s)
{

    base=nullptr;

    switch (s) {
    case MyEnum::halcon_operator::drawCircle:
        //创建算子对象
        base=new DrawCircles(hv_WindowHandle,&m_referImage,&m_isDraw);
        break;
    case MyEnum::halcon_operator::drawellipes:

        // base=new DrawEllipses(&m_region,hv_WindowHandle,&hv_Row,&hv_Column,&hv_Phi,&hv_Radius1,&hv_Radius2,&m_isDraw);

        break;

    case MyEnum::halcon_operator::threshold:
        base=new Thresholds(&m_referImage);
        break;
    case MyEnum::halcon_operator::openingCircle:
        base=new  OpeningCircle(&m_referImage);
        break;
    default:
        break;
    }
    return  base;
}

