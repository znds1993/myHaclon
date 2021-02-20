#include "mythread.h"
#include"QDebug"
MyThread::MyThread()
{

}
void MyThread::run(){

    while(falg){
        try {
            GrabImageAsync(&c_Operator.ho_Image, c_Operator.hv_AcqHandle,-1);
            emit threadSignals();
        } catch (HalconCpp::HException& e) {

        }
    }
    QThread::sleep(2);
}


