#include "titlebar.h"
#include "ui_titlebar.h"

Titlebar::Titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Titlebar)
{
    ui->setupUi(this);
    this->setFixedHeight(30);
    connect(ui->clostBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

Titlebar::~Titlebar()
{
    delete ui;
}
