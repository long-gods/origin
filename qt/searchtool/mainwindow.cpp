#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(search()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search()
{
for(int i=0;i<100;i++)
    {
    ui->tableWidget->insertRow(i); //插入新行
    QTableWidgetItem *item = new QTableWidgetItem();
    QTableWidgetItem *item1 = new QTableWidgetItem();
    QTableWidgetItem *item2 = new QTableWidgetItem();
    QTableWidgetItem *item3 = new QTableWidgetItem();

    //设置对应的图标、文件名称、最后更新时间、对应的类型、文件大小

    item->setText("dsa"+QString::number(i)); //icon为调用系统的图标，以后缀来区分
//    item->setText("dsa");
    item1->setText("dsa");
    item2->setText("dsa"); //type为调用系统的类型，以后缀来区分

    item3->setText("dsa");

    ui->tableWidget->setItem(i, 0, item);
    ui->tableWidget->setItem(i, 1, item1);
    ui->tableWidget->setItem(i, 2, item2);
    ui->tableWidget->setItem(i, 3, item3);
}
}
