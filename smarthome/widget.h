#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QString username[10]={"user"};
    QString password[10]={"password"};
public:
    explicit Widget(QWidget *parent = 0);
    bool search(QString usern,QString passw);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
