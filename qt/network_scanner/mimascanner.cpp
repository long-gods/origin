#include "mimascanner.h"
#include "ui_mimascanner.h"
#include"QFileDialog"
#include"QMessageBox"

mimascanner::mimascanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mimascanner)
{
    ui->setupUi(this);
    m=new mimascan;
    connect(m,SIGNAL(sent_res(QString)),this,SLOT(show_res(QString)));
}

mimascanner::~mimascanner()
{
    delete ui;
}

void mimascanner::on_pushButton_clicked()
{
//    QString file,filename,filePath;
    url=new QUrl("file:///D:/");
    *url=QFileDialog::getOpenFileUrl(this, tr("选择一个文本文件"), *url, tr("txt Files (*.txt)"));
    ui->comboBox->addItem(url->toLocalFile());
//    QFile file(url->toLocalFile());

//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        return;
//    }
//    QTextStream in(&file);
//    qDebug()<<in.readLine();
//    qDebug()<<in.readLine();
//    qDebug()<<in.readLine();
}


void mimascanner::on_pushButton_2_clicked()
{
    if(url->isEmpty())
    {
        QMessageBox::information(NULL,"错误","请选择密码本文件");
        return;
    }
    else
    {
        m->url=ui->lineEdit_2->text();
        qDebug()<<url->toLocalFile();
        m->file=url->toLocalFile();
        m->name=ui->lineEdit->text();
        m->init();
        m->run();
    }
}

void mimascanner::show_res(QString res)
{
    ui->lineEdit_3->setText(res);
    QString filePath =QString(QCoreApplication::applicationDirPath()+"/log/ftp.txt");

    QFile file(filePath);

    if(!file.open(QIODevice::Append)){

        return;

    }

    file.write("目标ip:");
    file.write(ui->lineEdit_2->text().toUtf8());
    file.write(" 用户名:");
    file.write(ui->lineEdit->text().toUtf8());
    file.write(" 密码:");
    file.write(res.toUtf8());

    file.write("\n");

    file.close();
}

