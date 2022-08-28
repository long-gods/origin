#ifndef HOSTSCAN_H
#define HOSTSCAN_H

#include <QWidget>
#include"hostscanner.h"
namespace Ui {
class hostScanner;
}

class hostScanner : public QWidget
{
    Q_OBJECT

public:
    explicit hostScanner(QWidget *parent = nullptr);
    bool checkip(QString ip);
    ~hostScanner();

private slots:
    void on_pushButton_clicked();
    void setBar(int value);
    void lot(QString url);
    void on_pushButton_2_clicked();

private:
    Ui::hostScanner *ui;
    QString ip;
    host* scan;
    int start;
    int end;
};

#endif // HOSTSCAN_H
