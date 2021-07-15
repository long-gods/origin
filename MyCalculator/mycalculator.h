#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QStack>
#include <QPainter>
#include <QDateTime>


QT_BEGIN_NAMESPACE
namespace Ui { class Mycalculator; }
QT_END_NAMESPACE

class Mycalculator : public QMainWindow
{
    Q_OBJECT

private:
    QLineEdit *lineEdit;//显示框
    QString input; //输入框

    void MYcalculate();

private slots://定义槽函数
    void buttonClicked();

public:
    explicit MyCalculator(QWidget *parent = 0);
    ~MyCalculator();

    // 增加 paintEvent() 的声明
    protected:
        void paintEvent(QPaintEvent *); //重写paintEvent()
private:
    Ui::Mycalculator *ui;
};
#endif // MYCALCULATOR_H
