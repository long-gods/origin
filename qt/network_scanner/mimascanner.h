#ifndef MIMASCANNER_H
#define MIMASCANNER_H

#include <QWidget>
#include<QTcpSocket>
#include"mimascan.h"
namespace Ui {
class mimascanner;
}

class mimascanner : public QWidget
{
    Q_OBJECT

public:
    QUrl* url;
    explicit mimascanner(QWidget *parent = nullptr);
    ~mimascanner();
    QTcpSocket* socket;
    mimascan* m;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void show_res(QString res);

private:
    Ui::mimascanner *ui;
};

#endif // MIMASCANNER_H
