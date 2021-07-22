#include "myclient.h"
#include "ui_myclient.h"

Myclient::Myclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Myclient)
{
    ui->setupUi(this);
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
    if(!buffer.isEmpty())
    {
        ui->textEdit->append(buffer);
    }
}

void Myclient::on_pushButton_clicked()
{
    QString str=ui->textEdit_2->toPlainText();
    if(str!="")
        tcpClient->write(str.toLatin1());
}
