#include "mythread.h"
#include<qdebug.h>
typedef void ( *SetKeyBoardHook)(void); //定义函数指针

mythread::mythread(QObject *parent) : QThread(parent)
{
    isStop = false;
}


void mythread::closeThread()
{
    isStop = true;
}

void mythread::run()
{
    QLibrary mylib("serverDll.dll");
        if(mylib.load())
        {
            qDebug() << "dllhook加载成功";
            SetKeyBoardHook open = (SetKeyBoardHook)mylib.resolve("server");
            if(open)
            {
                qDebug() << "SetKeyBoardHook加载成功";
                open();
            }
        }
}

