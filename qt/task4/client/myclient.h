#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>

namespace Ui {
class Myclient;
}

class Myclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit Myclient(QWidget *parent = 0);
    ~Myclient();

private:
    Ui::Myclient *ui;
    QTcpSocket *tcpClient;
private slots:
    void ReadData();
//    void ReadError(QAbstractSocket::SocketError);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // MYCLIENT_H
