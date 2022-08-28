#ifndef XIUTANSCANNER_H
#define XIUTANSCANNER_H
#include<QThread>
#include"winsock2.h"
#include<pcap.h>


class xiutanscanner : public QThread
{
    Q_OBJECT
private:
    pcap_if_t* current_dev;
public:
    xiutanscanner();
    void run();
    void stop();
    bool stopped=0;
    void getdev(pcap_if_t* current_dev);
};

#endif // XIUTANSCANNER_H
