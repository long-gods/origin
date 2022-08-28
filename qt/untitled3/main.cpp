#include "mainwindow.h"
#include"QtSql/QSqlDatabase"
#include"QtSql/QSqlError"
#include"QMessageBox"
#include <QApplication>

int main(int argc, char *argv[])
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
        }
        else {
            QMessageBox box;
            box.setText(db.lastError().text());
            box.exec();
        }
    //输出可用数据库
//        qDebug()<<"available drivers:";
//        QStringList drivers = QSqlDatabase::drivers();
//        foreach(QString driver, drivers)
//            qDebug()<<driver;


}
