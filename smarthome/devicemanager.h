#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <QWidget>

namespace Ui {
class devicemanager;
}

class devicemanager : public QWidget
{
    Q_OBJECT

public:
    explicit devicemanager(QWidget *parent = 0);
    ~devicemanager();

private:
    Ui::devicemanager *ui;
};

#endif // DEVICEMANAGER_H
