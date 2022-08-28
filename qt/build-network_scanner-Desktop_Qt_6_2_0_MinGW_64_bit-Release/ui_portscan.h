/********************************************************************************
** Form generated from reading UI file 'portscan.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSCAN_H
#define UI_PORTSCAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_portscan
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QTextBrowser *textBrowser;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *portscan)
    {
        if (portscan->objectName().isEmpty())
            portscan->setObjectName(QString::fromUtf8("portscan"));
        portscan->resize(605, 326);
        portscan->setMinimumSize(QSize(420, 300));
        lineEdit = new QLineEdit(portscan);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 201, 20));
        label = new QLabel(portscan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 39, 20));
        textBrowser = new QTextBrowser(portscan);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 60, 251, 211));
        spinBox = new QSpinBox(portscan);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(350, 10, 51, 22));
        spinBox->setMaximum(65536);
        spinBox_2 = new QSpinBox(portscan);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(350, 40, 51, 22));
        spinBox_2->setMaximum(65536);
        spinBox_2->setValue(65535);
        lineEdit_2 = new QLineEdit(portscan);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(360, 90, 31, 21));
        label_2 = new QLabel(portscan);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 90, 39, 21));
        label_3 = new QLabel(portscan);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 30, 39, 11));
        pushButton = new QPushButton(portscan);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 220, 80, 18));
        progressBar = new QProgressBar(portscan);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(290, 150, 111, 21));
        progressBar->setValue(0);
        pushButton_2 = new QPushButton(portscan);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 250, 80, 18));
        label_4 = new QLabel(portscan);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 190, 181, 16));

        retranslateUi(portscan);

        QMetaObject::connectSlotsByName(portscan);
    } // setupUi

    void retranslateUi(QDialog *portscan)
    {
        portscan->setWindowTitle(QCoreApplication::translate("portscan", "\347\253\257\345\217\243\346\211\253\346\217\217", nullptr));
        label->setText(QCoreApplication::translate("portscan", "Address\357\274\232", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("portscan", "10", nullptr));
        label_2->setText(QCoreApplication::translate("portscan", "\347\272\277\347\250\213\346\225\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("portscan", "\347\253\257\345\217\243\350\214\203\345\233\264\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("portscan", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("portscan", "\346\232\202\345\201\234", nullptr));
        label_4->setText(QCoreApplication::translate("portscan", "\346\255\243\345\234\250\346\211\253\346\217\217\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class portscan: public Ui_portscan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSCAN_H
