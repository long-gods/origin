#include "server.h"
#include "ui_server.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    ui->lineEdit->setText(QNetworkInterface().allAddresses().at(1).toString());   //获取本地IP
    tcpServer->listen(QHostAddress::Any, ui->lineEdit_2->text().toInt());
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}

server::~server()
{
    delete ui;
}

void server::NewConnectionSlot()
{
    currentClient = tcpServer->nextPendingConnection();
    tcpClient.append(currentClient);
    ui->comboBox->addItem(tr("%1:%2").arg(currentClient->peerAddress().toString().split("::ffff:")[1])\
                                          .arg(currentClient->peerPort()));
    connect(currentClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
//    connect(currentClient, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
}

void server::ReadData()
{
        // 由于readyRead信号并未提供SocketDecriptor，所以需要遍历所有客户端
        for(int i=0; i<tcpClient.length(); i++)
        {
            QByteArray buffer = tcpClient[i]->readAll();
            QJsonArray text;
            QString buf(buffer);
            if(buffer.isEmpty())    continue;

            static QString IP_Port, IP_Port_Pre;
            IP_Port = tr("[%1:%2]:").arg(tcpClient[i]->peerAddress().toString().split("::ffff:")[1])\
                                         .arg(tcpClient[i]->peerPort());
{
            // 若此次消息的地址与上次不同，则需显示此次消息的客户端地址
            if(IP_Port != IP_Port_Pre)
                ui->textEdit->append(IP_Port);

            ui->textEdit->append(buf);
            text.append(IP_Port+" "+buf);

            QJsonDocument document;
            document.setArray(text);
            QByteArray byteArray = document.toJson(QJsonDocument::Compact);
            for(int i=0; i<tcpClient.length(); i++)
            {
                    tcpClient[i]->write(byteArray);
            }
            }
            //更新ip_port
            IP_Port_Pre = IP_Port;
        }
        //指定连接

}


void server::on_pushButton_clicked()
{
    tcpServer->close();
        tcpServer->listen(QHostAddress::Any, ui->lineEdit_2->text().toInt());
}



