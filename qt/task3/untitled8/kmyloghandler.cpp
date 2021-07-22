#include "kmyloghandler.h"
#include<QFile>
KMyLogHandler::KMyLogHandler(QString str)
{
    this->file.setFileName(str);
}

void KMyLogHandler::open()
{
    file.open(QIODevice::ReadWrite |QIODevice::Text);
}
void KMyLogHandler::close()
{
    file.close();
}
QByteArray KMyLogHandler::bread()
{
    return file.readAll();
}
void KMyLogHandler::bwrite(QByteArray byte)
{
    file.resize(0);
    file.write(byte);
}
std::string KMyLogHandler::tread()
{
    std::string str=file.readAll().toStdString();
    return str;
}
void KMyLogHandler::twrite(std::string str)
{
    file.resize(0);
    file.write(str.data());
}

KMyLogHandler::~KMyLogHandler()
{
    if(!file.exists())
        file.close();
}
