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


MainWindow::MainWindow(QWizard *parent)
    : QWizard(parent)
{
    //! [0]
        setPage(Page_Conclusion, new ConclusionPage);
        setPage(Page_Intro, new IntroPage);
    //    setPage(Page_Evaluate, new EvaluatePage);
    //    setPage(Page_Register, new RegisterPage);
    //    setPage(Page_Details, new DetailsPage);


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
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1,0,0);
    vbox->addWidget(radio2,0,0);
    Group->setLayout(vbox);
    Group->resize(300,30);
    QVBoxLayout *layout = new QVBoxLayout;

    Group1 = new QGroupBox(tr("用户"));
    QCheckBox *check1 = new QCheckBox(tr("关键dox "));
    QCheckBox *check2 = new QCheckBox(tr("所有用户 "));
    QCheckBox *check3 = new QCheckBox(tr("当前用户 "));
    QCheckBox *check4 = new QCheckBox(tr("所有用户 "));
    radio1->setChecked(true);
    QVBoxLayout *vbox1 = new QVBoxLayout;
    vbox1->addWidget(check1);
    vbox1->addWidget(check2);
    vbox1->addWidget(check3);
    vbox1->addWidget(check4);


    QLineEdit *le=new QLineEdit("");
    QPushButton *push=new QPushButton("安装位置");
    vbox1->addWidget(le);
    vbox1->addWidget(push);

    Group->setLayout(vbox);
    Group1->setLayout(vbox1);

    layout->addWidget(Group,0,0);
    layout->addWidget(Group1,1,0);

    setLayout(layout);
}

int IntroPage::nextId() const
//! [17] //! [19]
{
    if (Group1->isChecked()) {
        return MainWindow::Page_Evaluate;
    } else {
        return MainWindow::Page_Register;
    }
}
//! [18] //! [19]

//! [20]
EvaluatePage::EvaluatePage(QWidget *parent)
    : QWizardPage(parent)
{


//! [21]

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(emailLabel, 1, 0);
    layout->addWidget(emailLineEdit, 1, 1);
    setLayout(layout);
//! [22]
}
//! [22]

//! [23]
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


