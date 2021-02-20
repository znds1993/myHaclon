#ifndef MYWIN_H
#define MYWIN_H
#include"QToolButton"
#include <QWidget>
#include"mythread.h"
namespace Ui {
class MyWin;
}

class MyWin : public QWidget
{
    Q_OBJECT

public:
    explicit MyWin(QWidget *parent = nullptr);
    ~MyWin();
    void Blob();
    void AddImage(const HalconCpp::HObject& image);
    void RunImage(const HalconCpp::HObject& image);
    void UpdateImage();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void contextMenuEvent(QContextMenuEvent* e);
private:
    void InitData();
    void InitUi();
    void moveImage(double motionX, double motionY);
    void setImagePart(int r1, int c1, int r2, int c2);
    void zoomImage(double x, double y, double scale);
    bool imageManageFlag,isOpenImage;
    //鼠标右键菜单属性
    QMenu *menu,*menu1;
    QAction *a1,*a2,*a3;
    void createMenu();
public:

    void  binding();
public:
    bool              mouseLeftPressed;
    double            startX, startY;
    int               windowWidth;
    int               windowHeight;

    double            ImgRow1, ImgCol1, ImgRow2, ImgCol2;
    bool               m_isfirst;
    //  线程
    MyThread  m_thread;
signals:
    //保存图片
  void save_image();
  //显示原图
  void select_Old_image();
private:
    Ui::MyWin *ui;
};
#endif // MYWIN_H
