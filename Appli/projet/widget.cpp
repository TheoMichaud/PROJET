#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonModeManuel_clicked()
{
   ui->stackedWidgetPage-> setCurrentIndex(2);
}

void Widget::on_pushButtonGo_clicked()
{
   ui->stackedWidgetPage-> setCurrentIndex(1);
}
