#ifndef DDOS_H
#define DDOS_H
#include"QThread"
#include<qobject.h>


class ddos:public QThread
{
    Q_OBJECT

    int threadnum, maxthread, port;
    char* DestIP;//鐩爣IP
public:
    void run();
    void stop();
    void getdIP(char* ip);
    void getport(int port);
    void start();
    bool stopped=true;
    int i = 0;
    ddos();
signals:
    void sentnum(int value);
};

#endif // DDOS_H
