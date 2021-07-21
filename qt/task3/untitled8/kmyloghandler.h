#ifndef KMYLOGHANDLER_H
#define KMYLOGHANDLER_H

#include <QObject>
#include<QFile>
#include<string>
class KMyLogHandler : public QObject
{
    Q_OBJECT
public:
    KMyLogHandler(){}
    KMyLogHandler(QString str);
    ~KMyLogHandler();

    void open();
    void close();
    QByteArray bread();
    void bwrite(QByteArray byte);
    std::string tread();
    void twrite(std::string str);

private:
    QFile file;
signals:

public slots:
};

#endif // KMYLOGHANDLER_H
