#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Primality_testing.h"
#include<QRegularExpression>
#include<QRegularExpressionValidator>
#include<QButtonGroup>
#include<string>
#include<qdebug.h>
#include<QFileSystemWatcher>
#include<QDir>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread1=new mythread;
    thread1->start();
    QRegularExpression regx("[0-9]+$");
             QValidator* validator = new QRegularExpressionValidator(regx, ui->lineEdit);
             QValidator* validator_2 = new QRegularExpressionValidator(regx, ui->lineEdit_8);
             QValidator* validator_3 = new QRegularExpressionValidator(regx, ui->lineEdit_9);
             ui->lineEdit->setValidator(validator);
             ui->lineEdit_8->setValidator(validator_2);
             ui->lineEdit_9->setValidator(validator_3);//设置为只能输入数字
    ui->lineEdit_8->setText("48539");
    ui->lineEdit_9->setText("48079");
    QButtonGroup * BtnGroupA = new QButtonGroup;
    BtnGroupA->addButton(ui->radioButton,0);
    BtnGroupA->addButton(ui->radioButton_2,1);
    BtnGroupA->setExclusive(true);//设置radioButton两个互斥
}

MainWindow::~MainWindow()
{
    thread1->closeThread();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Primality_testing pri;
    if(ui->radioButton->isChecked()){
        if(pri.Miller_Rabin(ui->lineEdit->text().toLongLong()))
            ui->lineEdit_2->setText("是素数");
        else
            ui->lineEdit_2->setText("不是素数");
    }
    else
        if(pri.commontest(ui->lineEdit->text().toLongLong())){
            if(pri.Miller_Rabin(ui->lineEdit->text().toLongLong()))
                ui->lineEdit_2->setText("是素数");
            else
                ui->lineEdit_2->setText("不是素数");
        }
}



void MainWindow::on_pushButton_5_clicked()
{
    set_p1(ui->lineEdit_8->text().toLongLong());
    set_p2(ui->lineEdit_9->text().toLongLong());
    N=p1*p2;
    Nn=(p1-1)*(p2-1);
    for(long long i=e;i<Nn;i++)
        if(Nn%i!=0)
        {
            e=i;
            break;
        }
    bigmoden b;
    for(long long i=d;i<Nn;i++)
        if(b.Quick_Multiply(e,i,Nn)==1)
        {
            d=i;
            break;
        }
    QString str=ui->lineEdit_10->text();
    std::wstring str1=str.toStdWString();
    wchar_t c;
    for(int i=0;i<str.length();i++)
    {
        c=(wchar_t)str1[i];
        miwen.append(b.Quick_Power(c,e,N));
    }
    str="";
    for(auto i:miwen)
        str+=QString::number(i);
    ui->lineEdit_11->setText(str);
}


void MainWindow::on_pushButton_6_clicked()
{
    std::wstring str;
    bigmoden b;
    for(auto s:miwen)
    {
        str+=(wchar_t)b.Quick_Power(s,d,N);
    }
    QString str1;
    str1=str1.fromStdWString(str);
    ui->lineEdit_12->setText(str1);
}

