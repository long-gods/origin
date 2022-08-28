#include "mysql.h"

mysql::mysql(QObject *parent) : QObject(parent)
{

}

bool mysql::mysql_connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("2");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        if (ok){
            QMessageBox box;
            box.setText("连接成功");
            box.exec();
            return true;
        }
        else {
            QMessageBox box;
            box.setText(db.lastError().text());
            box.exec();
            return false;
        }
}

