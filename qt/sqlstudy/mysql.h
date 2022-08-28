#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlError"
#include"QMessageBox"
#include <QApplication>

class mysql : public QObject
{
    Q_OBJECT
public:
    explicit mysql(QObject *parent = nullptr);
    bool mysql_connect();
    bool add_line();
signals:

};

#endif // MYSQL_H
