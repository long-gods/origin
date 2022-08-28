#include "webtest.h"
#include "ui_webtest.h"

webtest::webtest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::webtest)
{
    ui->setupUi(this);
}

webtest::~webtest()
{
    delete ui;
}
