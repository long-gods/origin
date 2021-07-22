/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName(QString::fromUtf8("server"));
        server->resize(565, 425);
        centralWidget = new QWidget(server);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(450, 160, 69, 22));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(450, 20, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 20, 54, 16));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 361, 361));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 70, 54, 12));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(450, 70, 113, 20));
        server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(server);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 565, 23));
        server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(server);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(server);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        server->setStatusBar(statusBar);

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QMainWindow *server)
    {
        server->setWindowTitle(QApplication::translate("server", "server", nullptr));
        label->setText(QApplication::translate("server", "Ip\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("server", "\347\253\257\345\217\243", nullptr));
        lineEdit_2->setText(QApplication::translate("server", "8080", nullptr));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
