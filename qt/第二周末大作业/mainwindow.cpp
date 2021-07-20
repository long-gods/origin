#include <QtWidgets>
#include<QObject>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "mainwindow.h"

static  QString path;

MainWindow::MainWindow(QWidget *parent)
    : QWizard(parent)
{
        ConclusionPage *page1=new ConclusionPage();
        IntroPage *page2=new IntroPage();
        EvaluatePage *page3=new EvaluatePage();
        RegisterPage *page4=new RegisterPage();

        setPage(Page_Conclusion, page1);
        setPage(Page_Intro,page2);
        setPage(Page_Evaluate,page3);
        setPage(Page_Register, page4);


        connect(page2,&IntroPage::send,page3,&EvaluatePage::getstr);
        setStartId(Page_Conclusion);

        setOption(HaveHelpButton, true);

        setWindowTitle(tr("界面安装"));
        resize(600,400);
}

MainWindow::~MainWindow()
{

}


ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    QString prot("用户协议");
    QTextEdit* le = new QTextEdit(prot);
    le->move(3,3);
    le->resize(300,300);
    CheckBox = new QCheckBox(tr("I agree to the terms of the license"));

    registerField("first.agree*", CheckBox);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(le);
    layout->addWidget(CheckBox);
    setLayout(layout);
}
int ConclusionPage::nextId() const
//! [17] //! [19]
{
    if (CheckBox->isChecked()) {
        return MainWindow::Page_Intro;
    } else {
        return MainWindow::Page_Conclusion;
    }
}

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    Group = new QGroupBox(tr("用户"));
    QRadioButton *radio1 = new QRadioButton(tr("当前用户 "));
    QRadioButton *radio2 = new QRadioButton(tr("所有用户 "));
    radio1->setChecked(true);
    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    Group->setLayout(vbox);
    Group->resize(300,30);
    QVBoxLayout *layout = new QVBoxLayout;

    Group1 = new QGroupBox(tr("用户"));
    QCheckBox *check1 = new QCheckBox(tr("关键dox "));
    QCheckBox *check2 = new QCheckBox(tr("所有用户 "));
    QCheckBox *check3 = new QCheckBox(tr("当前用户 "));
    QCheckBox *check4 = new QCheckBox(tr("所有用户 "));
    radio1->setChecked(true);
    QGridLayout *vbox1 = new QGridLayout;
    vbox1->addWidget(check1,0,0);

    vbox1->addWidget(check2,1,0);
    vbox1->addWidget(check3,0,1);
    vbox1->addWidget(check4,1,1);


    directoryComboBox = createComboBox(QDir::toNativeSeparators(QDir::currentPath()));
    connect(directoryComboBox->lineEdit(), &QLineEdit::returnPressed,
            this,&IntroPage::animateFindClick);
    QPushButton *push=new QPushButton("安装位置");

    connect(push,&QAbstractButton::clicked,this,&findpath);

    registerField("evaluate.path*", directoryComboBox);

    vbox1->addWidget(directoryComboBox);
    vbox1->addWidget(push);

    Group->setLayout(vbox);
    Group1->setLayout(vbox1);

    layout->addWidget(Group,0,0);
    layout->addWidget(Group1,1,0);

    setLayout(layout);
}

QComboBox *IntroPage::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

void IntroPage::animateFindClick()
{
    findButton->animateClick();
}

void IntroPage::findpath()
{
    QString directory =
        QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath()));
    qDebug()<<directory;
    this->filepath=directory;
    qDebug()<<this->filepath;
    emit send(this->filepath);
    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
}

int IntroPage::nextId() const

{
        return MainWindow::Page_Evaluate;
}



EvaluatePage::EvaluatePage(QWidget *parent)
    : QWizardPage(parent)
{

    m_pLeftToRightProBar = new QProgressBar(this);
    m_pLeftToRightProBar->setOrientation(Qt::Horizontal);  // 水平方向
    m_pLeftToRightProBar->setMinimum(0);  // 最小值
    m_pLeftToRightProBar->setMaximum(100);  // 最大值
    m_pLeftToRightProBar->setValue(50);  // 当前进度
//! [21]
    list=new QListWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("安装进度:")), 0, 0);
    layout->addWidget(m_pLeftToRightProBar,0,1);
    layout->addWidget(new QLabel(tr("安装列表：")),1,0);
    layout->addWidget(list, 2, 0, 1, 2);
    setLayout(layout);
    QFileInfoList li;
    li=findFiles(this->filepath);

//! [22]
}

void EvaluatePage::getstr(QString str)
{
    this->filepath=str;
}
QFileInfoList EvaluatePage::findFiles(const QString path)
{
    QDir dir(path);
    if (!dir.exists())
    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList lists = dir.entryInfoList();
    QStringList infolist = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    //QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir.entryInfoList(infolist));
    int i = 0;
    do{
        QFileInfo fileInfo = lists.at(i);
        if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
        {
            i++;
            continue;
        }
        bool bisDir = fileInfo.isDir();
        if(bisDir)
        {
            findFiles(fileInfo.filePath());
        }
        else
        {
            //这里就是你想要对文件的操作了
            for(int m = 0; m <infolist.size(); m++)
            {
                num++;
                //这里是获取当前要处理的文件名
                QString filename = infolist.at(m);
                QString filepath=fileInfo.absoluteFilePath();
                list->addItem(filepath+filename);
                m_pLeftToRightProBar->setValue(num);
                Sleep(1);
            }
            break;//这里一定要break退出while循环，因为infolist中的文件访问完之后，当前文件夹下已经没有任何文件了，这里是递归的返回
        }
        i++;
    }while(i < lists.size());//这里是list.size()，也就是当前文件夹下的文件夹数和文件数的和再+2
        return lists;
}

int EvaluatePage::nextId() const
{
    return MainWindow::Page_Register;
}
//! [23]

RegisterPage::RegisterPage(QWidget *parent)
    : QWizardPage(parent)
{
    grid = new QGridLayout();
    QLabel *label=new QLabel(tr("激活方式："));
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255, 255, 255));
    label->setAutoFillBackground(true);
    label->setPalette(palette);

    QComboBox *echoComboBox = new QComboBox;
    echoComboBox->addItem(tr("License key"));
    echoComboBox->addItem(tr("Password"));

    QPushButton *button=new QPushButton();
    button->setText("激活 ");

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);

    QCheckBox *checkBox = new QCheckBox(tr("跳过"));
    checkBox->setChecked(false);

    connect(echoComboBox, SIGNAL(activated(int)),
            this, SLOT(echoChanged(int)));
    nameLabel = new QLabel();
    pwdLabel = new QLabel();
    echoLineEdit = new QLineEdit;
    nameLineEdit = new QLineEdit;
    echoLineEdit->setFocus();
    grid->addWidget(nameLabel,1,0);
    grid->addWidget(echoLineEdit,2,0,1,4);
    echoLineEdit->setInputMask(">#####-#####-#####-#####-#####;#");

    grid->addWidget(label,0,0);
    grid->addWidget(echoComboBox,0,2,1,2);
    grid->addWidget(button,3,0,1,1);
    grid->addWidget(line,4,0,1,4);
    grid->addWidget(checkBox,5,3);

    setLayout(grid);
}


