#ifndef MYTHREAD_H
#define MYTHREAD_H
#include"QThread"
#include"HalconCpp.h"
#include"createoperator.h"
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();
    CreateOperator c_Operator;
    //    HalconCpp::HTuple *hv_WindowHandle;
    HalconCpp::HTuple *hv_AcqHandle;
    //    HalconCpp::HTuple H,W;
    HalconCpp::HObject  ho_Image;
    bool falg;
signals:
    void threadSignals();
};

#endif // MYTHREAD_H
