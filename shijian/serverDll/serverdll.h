#ifndef SERVERDLL_H
#define SERVERDLL_H

#include "serverDll_global.h"
#include<QtNetwork/qtcpserver.h>
#include<QtNetwork/qtcpsocket.h>
#include<QObject>
#include<QProcess>

class SERVERDLL_EXPORT ServerDll
{
public:
    ServerDll();
};

#endif // SERVERDLL_H


extern "C"
{
    SERVERDLL_EXPORT void server();
}
