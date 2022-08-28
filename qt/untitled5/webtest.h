#ifndef WEBTEST_H
#define WEBTEST_H

#include <QWidget>
#include<QtWebViewQuick/QtWebViewQuick>
namespace Ui {
class webtest;
}

class webtest : public QWidget
{
    Q_OBJECT

public:
    explicit webtest(QWidget *parent = nullptr);
    ~webtest();

private:
    Ui::webtest *ui;
};

#endif // WEBTEST_H
