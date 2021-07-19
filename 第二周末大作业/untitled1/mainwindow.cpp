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

MainWindow::MainWindow(QWizard *parent)
    : QWizard(parent)
{
    //! [0]
        setPage(Page_Conclusion, new ConclusionPage);
        setPage(Page_Intro, new IntroPage);
        setPage(Page_Evaluate, new EvaluatePage);
        setPage(Page_Register, new RegisterPage);


    //! [1]

        setStartId(Page_Conclusion);
    //! [2]

    //! [3]
    #ifndef Q_OS_MAC
    //! [3] //! [4]
        //setWizardStyle(ModernStyle);
    #endif
    //! [4] //! [5]
        setOption(HaveHelpButton, true);
    //! [5] //! [6]
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

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
    path=directoryComboBox->findText(directory);
}

int IntroPage::nextId() const
//! [17] //! [19]
{
        return MainWindow::Page_Evaluate;
}
//! [18] //! [19]

//! [20]
EvaluatePage::EvaluatePage(QWidget *parent)
    : QWizardPage(parent)
{

    m_pLeftToRightProBar = new QProgressBar(this);
    m_pLeftToRightProBar->setOrientation(Qt::Horizontal);  // 水平方向
    m_pLeftToRightProBar->setMinimum(0);  // 最小值
    m_pLeftToRightProBar->setMaximum(100);  // 最大值
    m_pLeftToRightProBar->setValue(50);  // 当前进度
//! [21]
    filesTable=new QTableWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel(tr("安装进度:")), 0, 0);
    layout->addWidget(m_pLeftToRightProBar,0,1);
    layout->addWidget(new QLabel(tr("安装列表：")),1,0);
    layout->addWidget(filesTable, 2, 0, 1, 2);
    setLayout(layout);
    QFileInfoList li;
    li=findFiles(path);

//! [22]
}

QFileInfoList EvaluatePage::findFiles(const QString path)
{
    QDir dir(path);
        QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

        for(int i = 0; i != folder_list.size(); i++)
        {
             QString name = folder_list.at(i).absoluteFilePath();
             QFileInfoList child_file_list = findFiles(name);
             file_list.append(child_file_list);
        }

        return file_list;
}

int EvaluatePage::nextId() const
{
    return MainWindow::Page_Conclusion;
}
//! [23]

RegisterPage::RegisterPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Register Your Copy of <i>Super Product One</i>&trade;"));
    setSubTitle(tr("If you have an upgrade key, please fill in "
                   "the appropriate field."));

    nameLabel = new QLabel(tr("N&ame:"));
    nameLineEdit = new QLineEdit;
    nameLabel->setBuddy(nameLineEdit);

    upgradeKeyLabel = new QLabel(tr("&Upgrade key:"));
    upgradeKeyLineEdit = new QLineEdit;
    upgradeKeyLabel->setBuddy(upgradeKeyLineEdit);

    registerField("register.name*", nameLineEdit);
    registerField("register.upgradeKey", upgradeKeyLineEdit);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(upgradeKeyLabel, 1, 0);
    layout->addWidget(upgradeKeyLineEdit, 1, 1);
    setLayout(layout);
}


