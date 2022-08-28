#ifndef SERVER_H
#define SERVER_H

#include "server_global.h"
#include <QTcpServer>
class SERVER_EXPORT Server
{
public:
    Server();
    void start();
};

#endif // SERVER_H
