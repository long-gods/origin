#ifndef HOSTSCANNER_H
#define HOSTSCANNER_H
#include<QObject>
#include<QThread>
#include<QUdpSocket>
#include<QQueue>
#include<QtNetwork>
#include<QMutex>
#include<QProgressBar>
#include <QGraphicsItem>

class host:public QThread
{
    Q_OBJECT
public:
    host();
    void run();
    void stop();
    QQueue <int> Q;
    QString ip;
    void generate(int start,int end);
    bool stopped=0;
    int nowip;

signals:
    void sentnowip(int val);
    void sig3(QString url);
};

#endif // HOSTSCANNER_H
