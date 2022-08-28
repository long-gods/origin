#ifndef DOS_ATTCK_H
#define DOS_ATTCK_H

#include <QWidget>
#include"dos.h"
#include"ddos.h"

namespace Ui {
class dos_attck;
}

class dos_attck : public QWidget
{
    Q_OBJECT

public:
    explicit dos_attck(QWidget *parent = nullptr);
    dos* dos1;
    ddos* ddo;
    ~dos_attck();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void set(int value);

private:
    Ui::dos_attck *ui;
};

#endif // DOS_ATTCK_H
