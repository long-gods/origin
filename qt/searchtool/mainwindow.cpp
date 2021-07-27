#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>
#include<QFile>
#include<QDir>
#include<QFileIconProvider>
#include<QString>
#include<QDateTime>
#include<vector>
#include"cnlhelper.h"
#include<QDebug>
QString path="C:\\Users\\wps\\Desktop";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    pop=new QMenu(ui->tableWidget);
    action=new QAction("打开",this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QDir fileDir(path);
    QFileInfoList fileinfolist=fileDir.entryInfoList();
    QFileIconProvider icon_provider;
    for(int i=0;i<fileinfolist.count();i++)
    {
        insertrow(i,i);
    }
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));

}

void MainWindow::insertrow(int i,int j)
{
    QDir fileDir(path);
    QFileInfoList fileinfolist=fileDir.entryInfoList();
    QFileIconProvider icon_provider;
    ui->tableWidget->insertRow(j); //插入新行
    QTableWidgetItem *item = new QTableWidgetItem();
    QTableWidgetItem *item1 = new QTableWidgetItem();
    QTableWidgetItem *item2 = new QTableWidgetItem();
    QTableWidgetItem *item3 = new QTableWidgetItem();

//设置对应的图标、文件名称、最后更新时间、对应的类型、文件大小

    item->setIcon(icon_provider.icon(fileinfolist.at(i)));
    item->setText(fileinfolist.at(i).fileName());
    item1->setText(fileinfolist.at(i).filePath());
    item2->setText(QString::number(fileinfolist.at(i).size()));
    item3->setText(fileinfolist.at(i).lastModified().toString());

    ui->tableWidget->setItem(j, 0, item);
    ui->tableWidget->setItem(j, 1, item1);
    ui->tableWidget->setItem(j, 2, item2);
    ui->tableWidget->setItem(j, 3, item3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search(QString name)
{
    ui->tableWidget->setRowCount(0); //函数清除表格数据区的所有内容，但是不清除表头。
    QDir fileDir(path);
    QFileInfoList fileinfolist=fileDir.entryInfoList();
    bool b = name.contains(QRegExp("[\\x4e00-\\x9fa5]+"));
if(name=="")
{
    for(int i=0;i<fileinfolist.count();i++)
    {
        insertrow(i,i);
    }
}
else if(b)
{
    std::vector<double> check;
    for(int i=0;i<fileinfolist.count();i++)
    {
        int j=0;
        if(fileinfolist.at(i).fileName().contains(QRegExp("[\\x4e00-\\x9fa5]+")))
        {
            QString filename=fileinfolist.at(i).fileName();
            double m=0;
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[0]==filename[l])
                        m++;
                }
            if(m!=0)
            {
                double m=m/filename.length();
                if(check.empty())
                {
                    insertrow(i,0);
                    check.insert(check.begin()+j,m);
                }
                else
                {
                    for(auto n:check)
                {
                    if(n<=m)
                    {
                        insertrow(i,j);
                        check.insert(check.begin()+j,m);
                        break;
                    }
                    else
                    {
                        j++;
                    }
                }
                    if(j==check.size())
                    {
                        insertrow(i,j);
                        check.insert(check.begin()+j,m);
                    }
                }

            }
        }
    }

}
else
{
    std::vector<double> check;
    for(int i=0;i<fileinfolist.count();i++)
    {
        int j=0;
        double m=0;
        QString filename;
        if(fileinfolist.at(i).fileName().contains(QRegExp("[\\x4e00-\\x9fa5]+")))
        {
            filename=CNLHelper::Instance()->CNToEL(fileinfolist.at(i).fileName());
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[0]==filename[l])
                        m++;
                }
        }
        else
        {
            filename=fileinfolist.at(i).fileName();
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[0]==filename[l])
                        m++;
                }
        }
        m/=filename.length();
        if(m!=0)
        {
            double m=m/filename.length();
            if(check.empty())
            {
                insertrow(i,0);
                check.insert(check.begin()+j,m);
            }
            else
            {
                for(auto n:check)
            {
                    qDebug()<<n;
                if(n<=m)
                {
                    insertrow(i,j);
                    check.insert(check.begin()+j,m);
                    break;
                }
                else
                {
                    j++;
                }
            }
                if(j==check.size())
                {
                    insertrow(i,j);
                    check.insert(check.begin()+j,m);
                }
            }
        }
    }
}
}

void MainWindow::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    pop->addAction(action);
    pop->exec(QCursor::pos());
}
