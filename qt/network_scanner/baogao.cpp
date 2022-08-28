#include "baogao.h"
#include "ui_baogao.h"
#include<QFile>
#include<QTextStream>
#include<QTime>
baogao::baogao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::baogao)
{
    ui->setupUi(this);
}

baogao::~baogao()
{
    delete ui;
}

void baogao::on_pushButton_clicked()
{
    ui->textBrowser->setText("");
    QString filePath =QString(QCoreApplication::applicationDirPath()+"/log.txt");
    QString filePath1 =QString(QCoreApplication::applicationDirPath()+"/log/ip.txt");

    QFile file(filePath);
    QFile file1(filePath1);

    if(!file1.open(QIODevice::ReadOnly)){

        return;

    }
    if(!file.open(QIODevice::Append)){
        return;
    }
    QTextStream out(&file);
    QTextStream in1(&file1);

    ui->textBrowser->append("本次扫描中存活的主机：");
    out<<QTime::currentTime().toString();
    out<<"\n";
    out<<"本次扫描中存活的主机：\n";
    while (!in1.atEnd()) {
    QString str=in1.readLine();
    ui->textBrowser->append("  "+str);
    out<<"  "+str;
    }
    out<<"\n";
    file1.close();
    QString filePath2 =QString(QCoreApplication::applicationDirPath()+"/log/port.txt");

    QFile file2(filePath2);

    if(!file2.open(QIODevice::ReadOnly)){

        return;

    }

    QTextStream in2(&file2);
    ui->textBrowser->append("本次扫描中开放的主机和端口：");
    out<<"本次扫描中开放的主机和端口：\n";
    while (!in2.atEnd()) {
    QString str=in2.readLine();
    ui->textBrowser->append("  "+str);
    out<<"  "+str;
    }
    out<<"\n";
    file2.close();
    QString filePath3 =QString(QCoreApplication::applicationDirPath()+"/log/ftp.txt");

    QFile file3(filePath3);

    if(!file3.open(QIODevice::ReadOnly)){

        return;

    }

    QTextStream in3(&file3);
    ui->textBrowser->append("本次扫描中使用ftp爆破的结果：");
    out<<"本次扫描中使用ftp爆破的结果：\n";

    while (!in3.atEnd()) {
        QString str=in3.readLine();
        ui->textBrowser->append("  "+str);
        out<<"  "+str;
    }
    out<<"\n";
    file3.close();
    file.close();
}

