#ifndef MYWIN_TWO_H
#define MYWIN_TWO_H
#include"createoperator.h"
#include <QWidget>
#include<QMap>
#include"MyWin.h"
#include<QMenu>
#include<QAction>
#include<QScrollArea>
#include<QString>
class _Laber {
public:
    _Laber(QLabel* la, QAction* act);
    QLabel* la;
    QAction* act;
};
class _toolButton{
public:
    _toolButton(QString names, HalconCpp::HObject *objs,QAction* qac);
    QString names;
    HalconCpp::HObject * objs;
    QAction* qac;
};
namespace Ui {
class Mywin_two;
}

class Mywin_two : public QWidget
{
    Q_OBJECT

public:
    explicit Mywin_two(MyWin* wi, QWidget* parent = nullptr);

    ~Mywin_two();
    MyWin* wi;
    QString pathName;
    //保存图片文件标识
    int coutFile = 0;
    //按钮布局
    QHBoxLayout* ql_son;
    //滚动条的窗口
    QWidget* wi_beas;
    //图片控件
    QLabel* label;
    //图片文件路径名
    QString fileName;
    void addObject(HalconCpp::HObject, MyWin* win);
    //右键菜单
    QMenu* meun;
    QAction* del;

    QMenu* meuns;
    QAction* clears;

    //显示算子输出图片
    QWidget*  wi_show;
    QToolButton* too;
    int v_tooCoutn=0;
    QVector<QToolButton*> v_too;
    QHBoxLayout* show_son;
    QMap<QToolButton*,_toolButton> m_to;
    void showImage(QMap<QString,HalconCpp::HObject*>& m,h_operators* h);

    //读入文件夹照片
    void readeDocument (QString part);
     HalconCpp::HObject ho_BinImage;

    //删除输出图片
     QMap<QToolButton*,h_operators*> dM;
     void deleOutputImage(h_operators* h);
private:
    //标识是哪个窗口
    bool ok=true;
    void enterEvent(QEvent* event);
    bool eventFilter(QObject*, QEvent*);
    QMap<QString, _Laber> labelArray;
    Ui::Mywin_two* ui;

signals:
    void del_file();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MYWIN_TWO_H
