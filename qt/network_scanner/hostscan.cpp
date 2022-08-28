#include "hostscan.h"
#include "ui_hostscan.h"
#include"time.h"
#include<QRegularExpression>
#include<QMessageBox>
hostScanner::hostScanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hostScanner)
{
    ui->setupUi(this);
    scan=new host;
    setAcceptDrops(true);
    connect(scan,SIGNAL(sentnowip(int)),this,SLOT(setBar(int)));
    connect(scan, SIGNAL(sig3(QString)), this, SLOT(lot(QString)));
}

hostScanner::~hostScanner()
{
    delete ui;
}

void hostScanner::setBar(int value)
{
//    qDebug()<<value;
    ui->progressBar->setValue(value);
    QString str=QString("正在扫描： %1").arg(scan->ip+QString::number(value));
    ui->label_4->setText(str);
}

void hostScanner::lot(QString message)
{
    ui->textBrowser->append(message+":opened!");


    QString filePath =QString(QCoreApplication::applicationDirPath()+"/log/ip.txt");

    QFile file(filePath);

    if(!file.open(QIODevice::Append)){

        return;

    }

    file.write(message.toUtf8());

    file.write("\n");

    file.close();
}

bool hostScanner::checkip(QString ip)
{
    QRegularExpression rx2("\\d+\\.\\d+\\.\\d+\\.\\d+");
     if( !rx2.match(ip).hasMatch() )
           return false;
     //qDebug()<<"check true";
     return true;
}


void hostScanner::on_pushButton_clicked()
{
    QString desip=ui->lineEdit->text();
    ui->progressBar->setValue(0);
    if(!checkip(desip))
        {
                    QMessageBox::information(NULL,"错误","IP地址输入错误");
        }
        else
        {
             QStringList list=desip.split(".");
             ip=list[0]+'.'+list[1]+'.'+list[2]+'.';
             start=list[3].toInt();
             end=ui->lineEdit_3->text().toInt();
             ui->progressBar->setRange(start,end);
             scan->generate(start,end);
             scan->ip=ip;
             scan->stopped=0;
             int num=ui->lineEdit_2->text().toInt();
             for(int i=0;i<num;i++)
             {
                 scan->start();
             }
        }

}

void hostScanner::on_pushButton_2_clicked()
{
     scan->stopped=1;
}
