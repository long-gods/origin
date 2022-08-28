#ifndef MIMASCAN_H
#define MIMASCAN_H

#include <QObject>
#include<QThread>
#include<QTcpSocket>
#include<QUrl>
#include<QFile>
class mimascan : public QThread
{
    Q_OBJECT
public:
    mimascan();

public:
    void run();
    void stop();
//    QFtp* ftp;
    QTcpSocket* socket;
    QString url;
    QString file;
    QString name;
    bool connected=false;
    bool stopped=true;
    QString rpass;
    void init();
    void send_name();
private slots:
    void slotConnected();
    void dataReceived();
    void slotdisConnected();
signals:
    void sent_res(QString res);

};

#endif // MIMASCAN_H
