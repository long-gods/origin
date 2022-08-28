#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QProcess::startDetached(  "server.dll"  ,QStringList());

}

MainWindow::~MainWindow()
{
    delete ui;
}

