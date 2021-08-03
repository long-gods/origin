#include "devicemanager.h"
#include "ui_devicemanager.h"

devicemanager::devicemanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::devicemanager)
{
    ui->setupUi(this);
}

devicemanager::~devicemanager()
{
    delete ui;
}
