#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent*);
    QPainter *Paint;
};
#endif // MAINWINDOW_H
