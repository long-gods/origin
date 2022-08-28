#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QFile"
#include"qfiledialog.h"
#include<QCryptographicHash>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<QDir::currentPath();
}


void MainWindow::on_pushButton_2_clicked()
{
    //t->stop();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString file,filename,filePath;
    QUrl url("file:///D:/");
    url=QFileDialog::getOpenFileUrl(this, tr("选择一个文本文件"), url, tr("txt Files (*.txt)"));
    ui->lineEdit_3->setText(url.toLocalFile());
}


void MainWindow::readContent()
{
    qDebug()<<rep->readAll();
}

void MainWindow::finishedSlot(QNetworkReply *reply)
{
#if 1
     // Reading attributes of the reply
     // e.g. the HTTP status code
     QVariant statusCodeV =
     reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
     // Or the target URL if it was a redirect:
     QVariant redirectionTargetUrl =
     reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
     // see CS001432 on how to handle this

     // no error received?
     if (reply->error() == QNetworkReply::NoError)
     {
         // read data from QNetworkReply here

         // Example 1: Creating QImage from the reply
         //QImageReader imageReader(reply);
         //QImage pic = imageReader.read();

         // Example 2: Reading bytes form the reply
         QByteArray bytes = reply->readAll();  // bytes
         //QString string(bytes); // string
         QString string = QString::fromUtf8(bytes);

         qDebug()<<string;
     }
     // Some http error received
     else
     {
         // handle errors here
     }

     // We receive ownership of the reply object
     // and therefore need to handle deletion.
     reply->deleteLater();
#endif
}

void MainWindow::LoginFinish(QNetworkReply *reply)
{
    // when reply is no error
    if (reply->error() == QNetworkReply::NoError)
    {
    // decode json string
    QJsonParseError jsonEr;
    QJsonObject jsonOb = QJsonObject(QJsonDocument::fromJson(reply->readAll(),&jsonEr).object());
    qDebug()<<jsonOb;
    if(jsonEr.error == QJsonParseError::NoError)
    {
    QJsonObject account = jsonOb.take("account").toObject();
    if(account.isEmpty()){
    QMessageBox::information(NULL,"Information","Login error: return Json data is Empty ",QMessageBox::Ok);
    return;
    }
    // get userID
    QString fuid = QString::number(account.take("id").toInt(),10);
    this->uid = fuid;
//    emit senduid(fuid);
//    this->GetPlaylist(fuid);
    }
    else
    {
//    QMessageBox::information(NULL,"Information","Login error: return data i
    }
    }
    else {
//    QMessageBox::information(NULL,"Information","Login error: Request is fail",Q
    // 出现错误，打印出来，方便调试解决
    //QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAtt
    //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文
    //qDebug( "found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->
    //qDebug(qPrintable(reply->errorString()));
    }
    reply->deleteLater();
    delete t;
//    t = NULL;
}



















