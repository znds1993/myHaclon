#include "closingcircle.h"
#include "ui_closingcircle.h"

ClosingCircle::ClosingCircle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClosingCircle)
{
    ui->setupUi(this);
}

ClosingCircle::~ClosingCircle()
{
    delete ui;
}
