#ifndef CLOSINGCIRCLE_H
#define CLOSINGCIRCLE_H

#include <QWidget>

namespace Ui {
class ClosingCircle;
}

class ClosingCircle : public QWidget
{
    Q_OBJECT

public:
    explicit ClosingCircle(QWidget *parent = nullptr);
    ~ClosingCircle();

private:
    Ui::ClosingCircle *ui;
};

#endif // CLOSINGCIRCLE_H
