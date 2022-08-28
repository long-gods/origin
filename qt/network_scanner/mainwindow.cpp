#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hostscan.h"
#include"portscan.h"
#include"mimascanner.h"
#include"qprocess.h"
#include"qmessagebox.h"
#include"xiutan.h"
#include"dos_attck.h"
#include"QDebug"
#include"QProcess"
#include"dialog.h"
#include"baogao.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filePath1 =QString("D:/c++/chenjianglong/qt/build-network_scanner-Desktop_Qt_6_2_0_MinGW_64_bit-Release/release/log/ip.txt");
    QString filePath2 =QString("D:/c++/chenjianglong/qt/build-network_scanner-Desktop_Qt_6_2_0_MinGW_64_bit-Release/release/log/port.txt");
    QString filePath3 =QString("D:/c++/chenjianglong/qt/build-network_scanner-Desktop_Qt_6_2_0_MinGW_64_bit-Release/release/log/ftp.txt");


    QFile file1(filePath1);
    QFile file2(filePath2);
    QFile file3(filePath3);

    if(!file1.open(QIODevice::WriteOnly)){

        return;

    }

    file1.write("");

    file1.close();
    if(!file2.open(QIODevice::WriteOnly)){

        return;

    }

    file2.write("");

    file2.close();
    if(!file3.open(QIODevice::WriteOnly)){

        return;

    }

    file3.write("");

    file3.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hostScanner* host=new hostScanner;
    host->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    portscan* port=new portscan;
    port->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    xiutan* x=new xiutan;
    x->firstinit();
    x->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    mimascanner* m=new mimascanner;
    m->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    dos_attck *d=new dos_attck;
    d->show();
}



void MainWindow::on_pushButton_6_clicked()
{
    baogao *b=new baogao;
    b->show();
}

