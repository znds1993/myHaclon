#ifndef CREATEOPERATOR_H
#define CREATEOPERATOR_H
#include"QString"
#include"halconOperator/h_operators.h"
#include"myenum.h"
#include"QVector"
#include"QMap"
#include"QMultiMap"
#include "halconOperator/thresholds.h"
#include "halconOperator/drawCircles.h"
#include "halconOperator/drawellipses.h"
#include "halconOperator/drawrects.h"
#include "halconOperator/drawrotaterects.h"
#include"halconOperator/openingcircle.h"
class CreateOperator
{
public:
    CreateOperator();
    //---------------------QT变量区--------------------------
    // 枚举
    MyEnum enums;
    // 算子基类指针
    h_operators * base;
    //判断 是否在画ROI
    bool   m_isDraw;


    //--------------Halcon变量区--------------------------
    // 相机句柄
    HalconCpp:: HTuple  hv_AcqHandle;
    //窗口句柄
    HalconCpp::HTuple hv_WindowHandle;
    //图像的宽
    HalconCpp::HTuple imageWidth;
    //图像的高
    HalconCpp::HTuple imageHeight;
    // 读入的原图像
    HalconCpp:: HObject  ho_Image;
    //进行操作的图像
    HalconCpp::HObject m_referImage;

    //文件夹
    HalconCpp::HTuple  hv_ImageFiles, hv_Index;


    //---------------- 容器区-------------------------------
    //算子指针集合
    QMap<int,h_operators*> creat_opertor;
    //保存的文件名称
    QVector<QString> saveFilename;

    //-------------------方法区---------------------------------
    //创建算子
    h_operators *  createOperator( int s);

};

#endif // CREATEOPERATOR_H
