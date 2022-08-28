#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mythread.h"
#define LL long long

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    long long p1;
    long long p2;
public:
    MainWindow(QWidget *parent = nullptr);
    bool Exgcd(LL a, LL b, LL& x, LL& y);   //ax + by = gcd(a,b) = 1

    mythread *thread1;
    long long N;
    long long Nn;
    long long e=5;
    long long d=466721993;
    QVector<long long> miwen;
    void set_p1(long long p1){this->p1=p1;}
    void set_p2(long long p2){this->p2=p2;}
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
