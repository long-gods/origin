/*
 *mysql.h
 *说明：封装的SQL连接
*/

#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>

class MySql :public QObject
{
public:
    MySql(QObject *parent = 0);

    bool connDB();
    bool queryDB(const QString &sql);

private:
    QString dbDriver;
    QString dbName;
    QString userName;
    QString userPwd;
    QString hostName;
    int hostPort;
};
#endif
