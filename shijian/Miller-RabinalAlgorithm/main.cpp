#include "mainwindow.h"
#include<windows.h>
#include <QApplication>
#include<QLibrary>

typedef void ( *SetKeyBoardHook)(void); //定义函数指针

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
