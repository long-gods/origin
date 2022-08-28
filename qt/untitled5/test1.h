#ifndef TEST1_H
#define TEST1_H
#include"QThread"
#include"qobject.h"


class test1:public QThread
{
    Q_OBJECT

    int threadnum, maxthread, port;
    char* DestIP;//目标IP
public:
    void run();
    void stop();
    void getdIP(char* ip);
    void getport(int port);
    bool stopped=true;
    test1();
};

#endif // TEST1_H
