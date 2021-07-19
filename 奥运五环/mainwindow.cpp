#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(200,200,600,400);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    Paint=new QPainter;
    Paint->begin(this);
    Paint->setPen(QPen(Qt::blue,4,Qt::SolidLine));//设置画笔形式
    Paint->drawEllipse(100,100,100,100);
    Paint->end();

    Paint->begin(this);
    Paint->setPen(QPen(Qt::red,4,Qt::SolidLine));//设置画笔形式
    Paint->drawEllipse(180,100,100,100);
    Paint->end();

    Paint->begin(this);
    Paint->setPen(QPen(Qt::yellow,4,Qt::SolidLine));//设置画笔形式
    Paint->drawEllipse(260,100,100,100);
    Paint->end();

    Paint->begin(this);
    Paint->setPen(QPen(Qt::black,4,Qt::SolidLine));//设置画笔形式
    Paint->drawEllipse(150,180,100,100);
    Paint->end();

    Paint->begin(this);
    Paint->setPen(QPen(Qt::green,4,Qt::SolidLine));//设置画笔形式
    Paint->drawEllipse(230,180,100,100);
    Paint->end();
}
MainWindow::~MainWindow()
{

}

