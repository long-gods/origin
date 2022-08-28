#include "netbiosscanner.h"
#include "ui_netbiosscanner.h"

NetBiosscanner::NetBiosscanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetBiosscanner)
{
    ui->setupUi(this);
}

NetBiosscanner::~NetBiosscanner()
{
    delete ui;
}
