#include "portscan.h"
#include "ui_portscan.h"
#include<QFile>

portscan::portscan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::portscan)
{
    ui->setupUi(this);
    scan=new scanner();
    setAcceptDrops(true);
    connect(scan,SIGNAL(sentnowport(int)),this,SLOT(setBar(int)));
    connect(scan, SIGNAL(sig3(QString)), this, SLOT(lot(QString)));
}

portscan::~portscan()
{
    delete ui;
}

void portscan::setBar(int value)
{
    qDebug()<<value;
    ui->progressBar->setValue(value);
    QString str=QString("正在扫描： %1").arg(scan->ip);
    ui->label_4->setText(QString(str+":%1").arg(value));
}

void portscan::lot(QString message)
{
    ui->textBrowser->append(message);
    QString filePath =QString(QCoreApplication::applicationDirPath()+"/log/port.txt");

    QFile file(filePath);

    if(!file.open(QIODevice::Append)){

        return;

    }

    file.write(message.toUtf8());

    file.write("\n");

    file.close();
}

bool portscan::checkip(QString ip)
{
    QRegularExpression rx2("\\d+\\.\\d+\\.\\d+\\.\\d+");
    QRegularExpression rx1("www\\.");
    return rx2.match(ip).hasMatch()||rx1.match(ip).hasMatch();
}

void portscan::on_pushButton_clicked()
{
    QString desip=ui->lineEdit->text();
    ui->progressBar->setValue(0);
    if(this->isfile){
        ui->spinBox->setValue(scan->nowport);
        staport=ui->spinBox->value();
        endport=ui->spinBox_2->value();
        ui->progressBar->setRange(staport,endport);
        scan->stopped=0;
        int num=ui->lineEdit_2->text().toInt();
        while(!this->url.empty()){
            scan->generate(staport,endport);
            scan->ip=this->url.dequeue();
        }
        for(int i=0;i<num;i++)
        {
            scan->start();
        }
    }
    else{
    if(!checkip(desip))
        {
            ui->lineEdit->setText("ip 地址错误");
        }
        else
        {
             ui->spinBox->setValue(scan->nowport);
             ip=desip;
             staport=ui->spinBox->value();
             endport=ui->spinBox_2->value();
             ui->progressBar->setRange(staport,endport);
             scan->generate(staport,endport);
             scan->ip=ip;
             scan->stopped=0;
             int num=ui->lineEdit_2->text().toInt();
             for(int i=0;i<num;i++)
             {
                 scan->start();
             }
        }
    }
}

void portscan::on_pushButton_2_clicked()
{
     scan->stopped=1;
}

