#include "portscanner.h"
#include<QMutex>
#include<QThread>
#include<QProgressBar>
#include <QGraphicsItem>
#include<QtNetwork>
#include<QHash>

QHash<int,QString> port_name={{21,"ftp"},{22,"ssh"},{23,"telnet"},{25,"SMTP"},{69,"tftp"},{79,"finger Finger"},{80,"http"},{110,"POP3"},{113,"ident old"},{119,"NNTP"},{220,"IMAP3"},{443,"https"},{3306,"mysql"}};

scanner::scanner()
{
    this->stopped=0;
}

void scanner::generate(int startport,int endport)
{
    for(int i=startport;i<=endport;++i)
    {
        this->Q.enqueue(i);
    }
}

void scanner::run()
{
       QMutex mutex;
       QMutex text;
       QString ip=this->ip;
       while(!this->Q.empty()){
       QTcpSocket tsocket(0);
//       QUdpSocket usocket(0);
       tsocket.setProxy(QNetworkProxy::NoProxy);
       tsocket.abort();
//       usocket.setProxy(QNetworkProxy::NoProxy);
//       usocket.abort();
       mutex.lock();
       int tmpport =this->Q.dequeue();
       if(this->stopped)
       {
           mutex.unlock();
           this->nowport=tmpport;
           this->quit();
           break;
       }
       tsocket.connectToHost(ip,tmpport);
//       usocket.connectToHost(ip,tmpport);
       bool tres=tsocket.waitForConnected(100);
//       bool ures=usocket.waitForConnected(100);
//       qDebug()<<tres;
       if(tres)
       {
           text.lock();
           QString message=ip+":";
           message+=QString::number(tmpport,10)+" "+port_name[tmpport]+"  opened!";
           emit sig3(message);
           text.unlock();
       }
//       else if(ures)
//       {
//           text.lock();
//           QString message=ip+":";
//           message+=QString::number(tmpport,10)+"udp  opened!";
//           emit sig3(message);
//           text.unlock();
//       }
       emit sentnowport(tmpport);
       mutex.unlock();
       }
}
void scanner::stop()
{
    this->stopped=true;
}

