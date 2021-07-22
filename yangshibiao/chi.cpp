#include "chi.h"
#include "ui_chi.h"

chi::chi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chi)
{
    ui->setupUi(this);
}


chi::~chi()
{
    delete ui;
}
