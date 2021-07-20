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
QT_END_NAMESPACE


class MainWindow : public QWizard
{
    Q_OBJECT

public:
    MainWindow(QWizard *parent = nullptr);
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

    QComboBox *createComboBox(const QString &text = QString());
private slots:
    void findpath();
    void animateFindClick();
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

private:
    QProgressBar *m_pLeftToRightProBar;
    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QComboBox *directoryComboBox;
    QLabel *filesFoundLabel;
    QPushButton *findButton;
    QTableWidget *filesTable;

    QDir Dir;

    QFileInfoList findFiles(const QString path);
    void showFiles(const QStringList &files);
};
//! [5]

class RegisterPage : public QWizardPage
{
    Q_OBJECT

public:
    RegisterPage(QWidget *parent = 0);

private:
    QLabel *nameLabel;
    QLabel *upgradeKeyLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *upgradeKeyLineEdit;
};

class DetailsPage : public QWizardPage
{
    Q_OBJECT

public:
    DetailsPage(QWidget *parent = 0);


private:
    QLabel *companyLabel;
    QLabel *emailLabel;
    QLabel *postalLabel;
    QLineEdit *companyLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *postalLineEdit;
};

//! [6]

//! [6]
#endif // MAINWINDOW_H
