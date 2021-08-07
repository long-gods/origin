#include "widget.h"
#include "ui_widget.h"
#include"mysql.h"
#include<QMessageBox>
#include<mainwindow.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::search(QString usern,QString passw)
{
    for(int i=0;i<10;i++)
    {
        if(username[i]==usern&&password[i]==passw)
            return true;
    }
    return false;
}
void Widget::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString passwd = ui->lineEdit_2->text();


    if(search(name,passwd))
    {
        QMessageBox::information(this, tr("登录成功"),
                tr("登录成功！欢迎进入本系统！"),
                QMessageBox::Ok);
        this->close();
        mainwindow *m=new mainwindow;
        m->show();
    }
    else
    {
        QMessageBox::warning(this, tr("登录失败"),
                tr("用户名或密码错误！是否重新登录？"),
                QMessageBox::Yes|QMessageBox::No);

    }

}
