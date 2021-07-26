#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QWizard>
#include<QDir>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QComboBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QDir;
class QProgressBar;
class QTableWidget;
class QListWidget;
class QGridLayout;
QT_END_NAMESPACE


class MainWindow : public QWizard
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    enum {Page_Conclusion , Page_Intro, Page_Evaluate, Page_Register, Page_Details,
           };
    ~MainWindow();

};

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    ConclusionPage(QWidget *parent = 0);
        int nextId() const override;

private slots:

private:
    QCheckBox *CheckBox;
};

//! [4]
class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);
    void set();
    int nextId() const override;

private:
    QGroupBox *Group;
    QGroupBox *Group1;
    QComboBox *directoryComboBox;
    QPushButton *findButton;
    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QLabel *filesFoundLabel;
    QString filepath;

    QComboBox *createComboBox(const QString &text = QString());
private slots:
    void findpath();
    void animateFindClick();
signals:
    void send(QString str);
};
//! [4]

//! [5]
class EvaluatePage : public QWizardPage
{
    Q_OBJECT

public:
    EvaluatePage(QWidget *parent = 0);
    int nextId() const override;
    void findfile();
    int num=0;

private:
    QProgressBar *m_pLeftToRightProBar;
    QString filepath;
    QListWidget *list;
    QDir Dir;

    QFileInfoList findFiles(const QString path);
    void showFiles(const QStringList &files);
public slots:
    void getstr(QString str);

};
//! [5]

class RegisterPage : public QWizardPage
{
    Q_OBJECT

public:
    RegisterPage(QWidget *parent = 0);

private:
    QLabel *nameLabel=nullptr;
    QLabel *pwdLabel=nullptr;
    QGridLayout *grid;
    QLineEdit* echoLineEdit=nullptr;
    QLineEdit* nameLineEdit=nullptr;
};



//! [6]

//! [6]
#endif // MAINWINDOW_H
