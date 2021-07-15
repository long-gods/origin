#include "mycalculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mycalculator w;
    w.show();
    return a.exec();
}
