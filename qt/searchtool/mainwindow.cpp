#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>
#include<QFile>
#include<QFileDialog>
#include<QFileIconProvider>
#include<QString>
#include<QDateTime>
#include<vector>
#include"cnlhelper.h"
#include<QDebug>
#include<QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RegisterHotKey(HWND(winId()),0,MOD_ALT,VK_SPACE);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    watch=new QFileSystemWatcher;
    watch->addPath(path);
    pop=new QMenu(ui->tableWidget);
    action=new QAction("打开",this);
    action2=new QAction("删除",this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QDir fileDir(path);
    QFileInfoList fileinfolist=fileDir.entryInfoList();
//    QFileIconProvider icon_provider;
    for(int i=0;i<fileinfolist.count();i++)
    {
        insertrow(i,i,fileinfolist);
    }
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(search(QString)));
    connect(this->watch,SIGNAL(directoryChanged(QString)),this,SLOT(filesearch(QString)));
    connect(action,SIGNAL(triggered(bool)),this,SLOT(start()));
    connect(action2,SIGNAL(triggered(bool)),this,SLOT(del()));
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);
    MSG* msg= static_cast<MSG*>(message);
    if(msg->message==WM_HOTKEY)
    {
        switch (msg->wParam) {
                case 0:
                    check=!check;
                    break;
                default:
                    qDebug() << "被注入了其他热键.";
                }
        if(check)
            this->show();
        else
            this->hide();
        return true;
    }
    return false;
}

void MainWindow::filesearch(QString path)
{
    search(ui->lineEdit->displayText());
}

void MainWindow::insertrow(int i,int j,QFileInfoList fileinfolist)
{
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
    QRegularExpression QRegExp("[\\x4e00-\\x9fa5]+");
    bool b = name.contains(QRegExp.pattern());
if(name=="")
{
    for(int i=0;i<fileinfolist.count();i++)
    {
        insertrow(i,i,fileinfolist);
    }
}
else if(b)
{
    std::vector<double> check;
    for(int i=0;i<fileinfolist.count();i++)
    {
        int j=0;
        if(fileinfolist.at(i).fileName().contains(QRegExp.pattern()))
        {
            QString filename=fileinfolist.at(i).fileName();
            double m=0;
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[k]==filename[l])
                    {
                       m++;
                       break;
                    }
                }
            if(m!=0)
            {
                double m=m/filename.length();
                if(check.empty())
                {
                    insertrow(i,0,fileinfolist);
                    check.insert(check.begin()+j,m);
                }
                else
                {
                    for(auto n:check)
                {
                    if(n<=m)
                    {
                        insertrow(i,j,fileinfolist);
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
                        insertrow(i,j,fileinfolist);
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
        if(fileinfolist.at(i).fileName().contains(QRegExp.pattern()))
        {
            filename=CNLHelper::Instance()->CNToEL(fileinfolist.at(i).fileName());
            qDebug()<<filename;
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[k]==filename[l])
                    {
                        m++;
                        break;
                    }
                }
        }
        else
        {
            filename=fileinfolist.at(i).fileName();
            for(int k=0;k<name.length();k++)
                for(int l=0;l<filename.length();l++)
                   {
                    if(name[k]==filename[l])
                    {
                        m++;
                        break;
                    }
                }
        }
                qDebug()<<m;
        m/=filename.length();
        qDebug()<<m;
        if(m!=0)
        {
            if(check.empty())
            {
                insertrow(i,0,fileinfolist);
                check.insert(check.begin()+j,m);
            }
            else
            {
                for(auto n:check)
            {
                if(n<=m)
                {
                    insertrow(i,j,fileinfolist);
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
                    insertrow(i,j,fileinfolist);
                    check.insert(check.begin()+j,m);
                }
            }
        }
    }
}
}

void MainWindow::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    QPoint point1=QCursor::pos();

    QTableWidgetItem *item = ui->tableWidget->itemAt(pos);
    if(item != NULL&&item->column()==0)
    {
        filename=item->text();

        pop->clear(); //清除原有菜单
        pop->addAction(action);
        pop->addAction(action2);
        pop->exec(point1);
    }

}

void MainWindow::start()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(path+"\\"+filename));
}

void MainWindow::del()
{
    QFile file(path+"\\"+filename);
    file.remove();
}

void MainWindow::on_action_triggered()
{
    watch->removePath(path);
    QString directory =
        QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
    qDebug()<<directory;
    this->path=directory;
    watch->addPath(path);
    search(ui->lineEdit->displayText());
}
