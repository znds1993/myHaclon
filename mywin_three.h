#ifndef MYWIN_THREE_H
#define MYWIN_THREE_H
#include"createoperator.h"
#include <QWidget>
#include<QTreeWidgetItem>
#include<QMenu>
#include<QAction>
namespace Ui {
class Mywin_three;
}

class Mywin_three : public QWidget
{
    Q_OBJECT

public:
    explicit Mywin_three(QWidget *parent = nullptr);
    ~Mywin_three();

    //树控件
    QTreeWidget * treeWidget;
    //添加数据
    void addDate(QMap<QString,QVector<DateClass>*>& m);
    //存放数据
    QMap<QString,QVector<DateClass>*> m;

    QTreeWidgetItem item;

    //保存参数地址
   QMap <QTreeWidgetItem *,DateClass> hV;
   //判断是否再次执行同一个算子
   bool isAgain=false;

  //右键菜单
   QMenu* meun;
   QAction* del;

private:
    Ui::Mywin_three *ui;
};

#endif // MYWIN_THREE_H
