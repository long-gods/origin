#include "mainwindow.h"
#include<QtNetwork/qtcpserver.h>
#include<QtNetwork/qtcpsocket.h>
#include <QApplication>
#include<qdebug.h>
#include<QLibrary>
#include<qprocess.h>
typedef void ( *SetKeyBoardHook)(void); //定义函数指针

int main(int argc, char *argv[])
{
//    QProcess *process=new QProcess;
//    process->start("dir");
//    process->waitForFinished();
//    QString str(process->readAllStandardOutput());
//    qDebug()<<str;
    QProcess process;
    process.setProgram("cmd");
    QStringList argument;
    argument<<"/c"<<"dir";
    process.setArguments(argument);
    process.start();
    process.waitForStarted(); //等待程序启动
    process.waitForFinished();//等待程序关闭
    QString temp=QString::fromLocal8Bit(process.readAllStandardOutput()); //程序输出信息
    qDebug()<<temp;

//        QLibrary mylib("serverDll.dll");
//            if(mylib.load())
//            {
//                qDebug() << "dllhook加载成功";
//                SetKeyBoardHook open = (SetKeyBoardHook)mylib.resolve("server");
//                if(open)
//                {
//                    qDebug() << "SetKeyBoardHook加载成功";
//                    open();
//                }
//            }
//    return 0;
}
