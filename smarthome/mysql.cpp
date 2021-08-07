/*
 *mysql.cpp
 *说明：封装的SQL连接
*/
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include "mysql.h"

MySql::MySql(QObject *parent)
    :QObject(parent)
{
    dbDriver="QMYSQL";
    dbName="root";
    userName="root";
    userPwd="root";
    hostName="localhost";
    hostPort=3306;
    connDB();
}

bool MySql::connDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(dbDriver);//添加驱动
    db.setHostName(hostName); //设置主机名
    db.setDatabaseName(dbName); //设置数据库名
    db.setUserName(userName); //设置用户名
    db.setPassword(userPwd); //设置用户密码

    //发送连接
    if(!db.open())
    {
    //	qDebug() << QSqlDatabase::drivers();
        qDebug() << db.lastError();
        return false;
    }
    return true;
}

bool MySql::queryDB(const QString &sql)
{
    QSqlQuery query;
    query.exec(sql);

    if(query.next())
    {
        qDebug() << query.value(0).toString();
        return true;
    }
    return false;
}
