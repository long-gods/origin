/********************************************************************************
** Form generated from reading UI file 'myclient.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLIENT_H
#define UI_MYCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myclient
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Myclient)
    {
        if (Myclient->objectName().isEmpty())
            Myclient->setObjectName(QString::fromUtf8("Myclient"));
        Myclient->resize(960, 439);
        centralWidget = new QWidget(Myclient);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 571, 291));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 330, 191, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 340, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 50, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 100, 54, 12));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(740, 50, 113, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(740, 100, 113, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 170, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(750, 170, 75, 23));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(220, 330, 191, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 310, 54, 12));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 310, 54, 12));
        Myclient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Myclient);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 21));
        Myclient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Myclient);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Myclient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Myclient);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Myclient->setStatusBar(statusBar);

        retranslateUi(Myclient);

        QMetaObject::connectSlotsByName(Myclient);
    } // setupUi

    void retranslateUi(QMainWindow *Myclient)
    {
        Myclient->setWindowTitle(QCoreApplication::translate("Myclient", "Myclient", nullptr));
        pushButton->setText(QCoreApplication::translate("Myclient", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("Myclient", "\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("Myclient", "\347\253\257\345\217\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Myclient", "connect", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Myclient", "disconnect", nullptr));
        label_3->setText(QCoreApplication::translate("Myclient", "\350\276\223\345\205\245path", nullptr));
        label_4->setText(QCoreApplication::translate("Myclient", "\350\276\223\345\205\245\345\221\275\344\273\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Myclient: public Ui_Myclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIENT_H
