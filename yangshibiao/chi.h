#ifndef CHI_H
#define CHI_H

#include <QWidget>

namespace Ui {
class chi;
}

class chi : public QWidget
{
    Q_OBJECT

public:
    explicit chi(QWidget *parent = nullptr);
    bool emitCan=true;
    ~chi();
public slots:

private:
    Ui::chi *ui;
};

#endif // CHI_H
