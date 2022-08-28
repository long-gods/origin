#ifndef BAOGAO_H
#define BAOGAO_H

#include <QWidget>

namespace Ui {
class baogao;
}

class baogao : public QWidget
{
    Q_OBJECT

public:
    explicit baogao(QWidget *parent = nullptr);
    ~baogao();

private slots:
    void on_pushButton_clicked();

private:
    Ui::baogao *ui;
};

#endif // BAOGAO_H
