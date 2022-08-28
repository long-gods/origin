#include "myclient.h"
#include "ui_myclient.h"
#include"QDateTime"
#include<QJsonArray>
#include<QJsonDocument>
Myclient::Myclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Myclient)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    tcpClient=new QTcpSocket(this);
    tcpClient->abort();
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(ReadData()));
//    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ReadError(QAbstractSocket::SocketError)));
}

Myclient::~Myclient()
{
    delete ui;
}

void Myclient::on_pushButton_2_clicked()
{
    tcpClient->connectToHost(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
    if(tcpClient->waitForConnected(1000))
        ui->pushButton->setEnabled(true);
}

void Myclient::on_pushButton_3_clicked()
{
    tcpClient->disconnectFromHost();
    if (tcpClient->state() == QAbstractSocket::UnconnectedState || tcpClient->waitForDisconnected(1000))  //已断开连接则进入if{}
        ui->pushButton->setEnabled(false);
}

void Myclient::ReadData()
{
    QByteArray buffer = tcpClient->readAll();
    QString buf=buffer;
    if(!buffer.isEmpty())
    {
        ui->textEdit->append(buf);
    }
}

void Myclient::on_pushButton_clicked()
{
    QString str=ui->textEdit_2->toPlainText();
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    QJsonArray text;
    text.append(current_date);
    text.append(str);

    QJsonDocument Document;
    Document.setArray(text);
    QByteArray ByteArray=str.toUtf8();
//    QByteArray ByteArray=Document.toJson(QJsonDocument::Compact);
    if(str!="")
        tcpClient->write(ByteArray);
    ui->textEdit_2->setText("");
}
