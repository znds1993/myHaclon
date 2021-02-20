#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mywin.h"
#include <QMainWindow>
#include"QPushButton"
#include"mywin.h"
#include"QThread"
#include"mythread.h"
#include"QTableWidget"
#include"QAction"
#include"QTreeWidgetItem"
#include"QAction"
#include"QContextMenuEvent"
#include"halconOperator/drawcircles.h"
#include"mywin_two.h"
#include"mywin_three.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //  1修改数据接口为每算子类参数输入和输出，父类获取子类的参数虚方法， 每执行一个算子显示其输参到ui界面作为下一个算子的输入参，
    //  2定义抽象类继承算子基类，算子继承该类
    //    一，保存算子虚方法（保存算子的标识，参数）
    //    二，Qmap保存每个算子的对应的参数。
    //    三，写：ui界面编辑保存文件名，Qmap写入txt（k加“-”）
    //    四，读：读取选着的文（得到Qmap），再加到tablewiget中（创建添加方法），根据键（算子标识）创建算子对象，Qmap值（始化该算子参数setMessage（判断值得个数，传入所有的值））
    // 3 图标放json
private:
    Ui::MainWindow *ui;
    //初始化
    QAction *action1,*action2,*action3,*action4,*action6;//工具栏子项
    inti=0;
    void layouts();//界面

    void InitData();//数据

    void InitUi();//图片

    //相机方式
    bool isOpen=false;
    bool  stopCall=true;
    //QString转HTuple
    HalconCpp::HTuple QString2Tuple(QString str);
    //窗口
    MyWin * wi;

    //鼠标右键菜单
    QMenu* meun;
    QAction *moveUp,*moveDown ,*del,*vRaySun;
    bool isUnit;
    void createMeun();

    //tableWigte的行号
    int grid=0;
    // 移动行
    int row;
    //选中的行
    int  CheckedRow;

    void moveRow( QTableWidget *pTable, int nFrom, int nTo );

    //算子的标识
    int key;

    //树控件行的总数
    int tRow;

    int up;
    int lower;

    MyThread  myt;
    void startThread();
    void stopThread();

    //算子参数ui界面
    MyEnum enums;
    void ui_operator_found(int k);//创建ui界面
    DrawCircles * ui_drawCircles= nullptr;
    Thresholds * ui_thresholds=nullptr;
    OpeningCircle*  ui_OpeningCircle=nullptr;
    bool isControl=false;// 是否调参
    void dataInteraction (int k,h_operators * h);//ui数据交互


    //保存图片
    Mywin_two* mywin_two;
    void save_picture(QDockWidget *dow2);

    //显示原图
    void select_picture();

    //显示数据
    Mywin_three * mywin_three;

    //是否读挡
    bool isRead=false;
private slots:
    void runs(); //线程
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();

signals:
    //相机
    void camera();
};
#endif // MAINWINDOW_H
