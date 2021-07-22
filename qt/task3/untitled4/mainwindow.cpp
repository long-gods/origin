#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qfilesystemwatcher.h>
#include<QFile>
#include<QtDebug>

QFileSystemWatcher  m_watch;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   qDebug()<< m_watch.addPath("C:\\Users\\wps\\source\\repos\\chenjianglong\\qt\\task3\\log.txt");
     connect(&m_watch, SIGNAL(fileChanged(QString)), this, SLOT(fileUpdated()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileUpdated()
{
    QFile file("C:\\Users\\wps\\source\\repos\\chenjianglong\\qt\\task3\\log.txt");
    qDebug()<<file.open(QIODevice::ReadOnly);
    QString str=file.readAll();
    qDebug()<<str;
    ui->textEdit->setText(str);
    file.close();
}
