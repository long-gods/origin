#include "server.h"
#include<QTcp

Server::Server()
{
}

void start()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,1234);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}
