#ifndef PORTSCANNER_H
#define PORTSCANNER_H
#include<QThread>
#include<QTcpSocket>
#include <QQueue>


class scanner:public QThread
{
    Q_OBJECT
public:
    scanner();
    void run();//涓嶅璇达紝鑷繁Google
    void stop();//瀹炵幇绾跨▼瀹夊叏鍋滄锛岀敤Terminate鏄笉瀹夊叏鐨    void generate(int startport,int endport);
    QQueue <int> Q;
    QString ip;
    void generate(int startport,int endport);
    bool stopped=0;
    int nowport=0;

signals:
    void sentnowport(int value);
    void sig3(QString url);

};

#endif // PORTSCANNER_H
