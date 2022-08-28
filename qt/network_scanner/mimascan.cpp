#include "mimascan.h"
#include<QMessageBox>
#include<QApplication>
#include<QNetworkProxy>
mimascan::mimascan()
{

    socket=new QTcpSocket;
    socket->setProxy(QNetworkProxy::NoProxy);
//    connect(socket,&QTcpSocket::disconnected,this,&mimascan::slotdisConnected);
//    connect(socket,&QTcpSocket::connected,this,&mimascan::slotConnected);
//    connect(socket,&QTcpSocket::readyRead,this,&mimascan::dataReceived);
}

void mimascan::init()
{

}

void mimascan::run()
{
    qDebug()<<url;
    QFile file1(file);
    if(!file1.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::information(NULL,"错误","密码本文件无法打开");
    }
    QTextStream in(&file1);
    while(!in.atEnd()&&stopped)
    {
    socket->disconnectFromHost();
    rpass=in.readLine();
    socket->connectToHost(url,21);
    qDebug()<<socket->waitForConnected();
    qDebug()<<socket->waitForReadyRead();
    qDebug()<<socket->bytesAvailable();
    /* 读取Socket并存入datagram */
    QByteArray datagram = socket->readAll();

    /* 展示在textEdit */
    QString str = QString::fromLocal8Bit(datagram);
    qDebug()<<str;
    QString pick1="220";
    QString pick2="331";
    QString pick3="230";
    if(str.indexOf(pick1)==0)
    {
        QString str="USER ";
        QByteArray command = (str+name).toLatin1();
        command += '\n';
        socket->write(command);
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        /* 读取Socket并存入datagram */
        QByteArray datagram = socket->readAll();

        /* 展示在textEdit */
        QString str1 = QString::fromLocal8Bit(datagram);
        qDebug()<<str1;
        if(str1.indexOf(pick2)==0)
        {
            QString str="PASS ";
            QByteArray command = (str+rpass).toLatin1();
            command += '\n';
            socket->write(command);
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            /* 读取Socket并存入datagram */
            QByteArray datagram = socket->readAll();

            /* 展示在textEdit */
            QString str2 = QString::fromLocal8Bit(datagram);
            qDebug()<<str2;
            if(str2.indexOf(pick3)==0)
            {
                emit sent_res(rpass);
                return ;
            }
        }

    }
    QApplication::processEvents();

    }
        emit sent_res("破解失败");
}

void mimascan::slotdisConnected()
{
    emit sent_res("IP无法连接");
}

void mimascan::slotConnected()
{

}

void mimascan::dataReceived()
{
    while (socket->bytesAvailable())
    {
        /* 读取Socket并存入datagram */
        QByteArray datagram = socket->readAll();

        /* 展示在textEdit */
        QString str = QString::fromLocal8Bit(datagram);
        qDebug()<<str;
        QString pick1="220";
        QString pick2="331";
        QString pick3="230";
        if(str.indexOf(pick1)==0)
        {
            QString str="USER ";
            QByteArray command = (str+name).toLatin1();
            command += '\n';
            socket->write(command);
        }
        else if(str.indexOf(pick2)==0)
        {
            emit sent_res(rpass);
            QString str="PASS ";
            QByteArray command = (str+rpass).toLatin1();
            command += '\n';
            socket->write(command);
        }
        else if(str.indexOf(pick3)==0)
        {

        }
    }

}

void mimascan::send_name()
{

}
