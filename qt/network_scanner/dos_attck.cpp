#include "dos_attck.h"
#include "ui_dos_attck.h"


dos_attck::dos_attck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dos_attck)
{
    ui->setupUi(this);
    dos1=new dos;
    ddo=new ddos;
    connect(dos1,SIGNAL(sentnum(int)),this,SLOT(set(int)));
    connect(ddo,SIGNAL(sentnum(int)),this,SLOT(set(int)));
}


dos_attck::~dos_attck()
{
    delete ui;
    delete ddo;
    delete dos1;
}


void dos_attck::on_pushButton_clicked()
{
    dos1->start();
    dos1->gethost(ui->lineEdit->text());
    dos1->getport(ui->lineEdit_2->text().toInt());
    for(int i=0;i<10;i++)
        dos1->run();
}


void dos_attck::on_pushButton_3_clicked()
{
    dos1->stop();
}


void dos_attck::on_pushButton_2_clicked()
{
    ddo->start();
    QByteArray text = ui->lineEdit->text().toLatin1();
    char *data = new char[text.size() + 1];
    strcpy(data, text.data());

    ddo->getdIP(data);
    ddo->getport(ui->lineEdit_2->text().toInt());
    ui->label_2->setText("0");
    for(int i=0;i<10;i++)
           ddo->run();
}


void dos_attck::on_pushButton_4_clicked()
{
    ddo->stop();
}

void dos_attck::set(int value)
{
    ui->label_2->setText(QString::number(value));
}
