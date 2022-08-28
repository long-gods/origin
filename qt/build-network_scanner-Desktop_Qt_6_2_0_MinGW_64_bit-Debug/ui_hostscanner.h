/********************************************************************************
** Form generated from reading UI file 'hostscanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSTSCANNER_H
#define UI_HOSTSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hostScanner
{
public:
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLabel *label_4;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *hostScanner)
    {
        if (hostScanner->objectName().isEmpty())
            hostScanner->setObjectName(QString::fromUtf8("hostScanner"));
        hostScanner->resize(585, 391);
        lineEdit_2 = new QLineEdit(hostScanner);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(480, 80, 31, 21));
        label_2 = new QLabel(hostScanner);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(418, 81, 41, 20));
        pushButton_2 = new QPushButton(hostScanner);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 240, 80, 18));
        label = new QLabel(hostScanner);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 51, 20));
        lineEdit = new QLineEdit(hostScanner);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 141, 20));
        progressBar = new QProgressBar(hostScanner);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(410, 140, 111, 21));
        progressBar->setValue(0);
        pushButton = new QPushButton(hostScanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 210, 80, 18));
        textBrowser = new QTextBrowser(hostScanner);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 70, 251, 211));
        label_4 = new QLabel(hostScanner);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 180, 171, 16));
        lineEdit_3 = new QLineEdit(hostScanner);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(350, 20, 141, 20));

        retranslateUi(hostScanner);

        QMetaObject::connectSlotsByName(hostScanner);
    } // setupUi

    void retranslateUi(QWidget *hostScanner)
    {
        hostScanner->setWindowTitle(QCoreApplication::translate("hostScanner", "Form", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("hostScanner", "10", nullptr));
        label_2->setText(QCoreApplication::translate("hostScanner", "\347\272\277\347\250\213\346\225\260\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("hostScanner", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("hostScanner", "Address\357\274\232", nullptr));
        lineEdit->setText(QCoreApplication::translate("hostScanner", "192.168.123.137", nullptr));
        pushButton->setText(QCoreApplication::translate("hostScanner", "\345\274\200\345\247\213", nullptr));
        label_4->setText(QCoreApplication::translate("hostScanner", "\346\255\243\345\234\250\346\211\253\346\217\217\357\274\232", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("hostScanner", "200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hostScanner: public Ui_hostScanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSTSCANNER_H
