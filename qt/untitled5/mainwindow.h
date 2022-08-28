#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"HttpOp.h"
#include"test1.h"
#include<QNetworkRequest>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QtNetwork>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QNetworkReply* rep;
    HttpOp* t;
    QNetworkAccessManager* nam;
    QString uid;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void readContent();
    void finishedSlot(QNetworkReply *reply);

    void LoginFinish(QNetworkReply* r);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
