#ifndef DOS_H
#define DOS_H
#include<qobject.h>
#include<QThread>

class dos:public QThread
{
    Q_OBJECT
private:
    QString hostaddress;
    int port;
public:
    void gethost(QString host);
    void getport(int port);
    void run();
    void stop();
    void start();
    int num=0;
    bool stopped=true;
    dos();
signals:
    void sentnum(int value);
};

#endif // DOS_H
