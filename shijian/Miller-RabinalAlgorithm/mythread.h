#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include<QLibrary>
class mythread : public QThread
{
public:
    explicit mythread(QObject *parent = nullptr);
    void closeThread();

protected:
    virtual void run();

private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明

};

#endif // MYTHREAD_H
