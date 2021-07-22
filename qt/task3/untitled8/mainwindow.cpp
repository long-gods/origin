#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QByteArray>
#include<QDebug>
#include"QDateTime"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    KMyLogHandler file("C:\\Users\\wps\\source\\repos\\chenjianglong\\qt\\task3\\log.txt");
    file.open();
    QByteArray before=file.bread();
    file.open();
    QByteArray byte;
    QDateTime time=QDateTime::currentDateTime();
    QString times=time.toString("yyyy-MM-dd hh:mm:ss");
    byte=(times+" "+ui->lineEdit->displayText()).toUtf8();
    qDebug()<<byte;
    file.bwrite(byte+"\n"+before);
    qDebug()<<file.bread();
    file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    KMyLogHandler file("C:\\Users\\wps\\source\\repos\\chenjianglong\\qt\\task3\\log.txt");
    file.open();
    std::string before=file.tread();
    file.open();
    file.open();
    std::string byte;
    QDateTime time=QDateTime::currentDateTime();
    QString times=time.toString("yyyy-MM-dd hh:mm:ss");
    byte=(times+" "+ui->lineEdit_2->displayText()).toStdString();
    file.twrite(byte+"\n"+before);
    file.close();
}

