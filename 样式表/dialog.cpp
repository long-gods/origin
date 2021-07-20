#include "dialog.h"
#include "ui_dialog.h"
#include<QFile>
#include<QMouseEvent>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    loadStyleSheet(tr("main"));
}


void Dialog::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
    if(Qt::LeftButton == event->button() && 0 == (Qt::WindowMaximized & this->windowState()))
    {
        QPoint temp=event->globalPos();
        pLast=temp;    //记录鼠标按下的位置
        event->ignore();
    }
    m_bPressed = true; //标记鼠标为按下状态
    poss=pos();
}


void Dialog::mouseMoveEvent(QMouseEvent * event)
{
    if(this->isMaximized()) //如果当前是最大化，则不允许移动
        return;

    if((event->buttons() & Qt::LeftButton) && m_bPressed)//是否左击
    {

        QPoint ptemp=event->globalPos();          //当前鼠标全局位置
        ptemp=ptemp-pLast;                        //计算移动变量
        ptemp=ptemp+poss;                        //窗口原始位置（pos()） + 鼠标移动变量（ptemp） = 最终窗口位置
        move(ptemp);                              //移动窗口到新的位置
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent * event)
{
    QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    event->ignore();

    m_bPressed = false;
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/res/" + sheetName.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}
