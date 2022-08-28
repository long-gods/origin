/********************************************************************************
** Form generated from reading UI file 'dos_attck.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOS_ATTCK_H
#define UI_DOS_ATTCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dos_attck
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *dos_attck)
    {
        if (dos_attck->objectName().isEmpty())
            dos_attck->setObjectName(QString::fromUtf8("dos_attck"));
        dos_attck->resize(459, 336);
        lineEdit = new QLineEdit(dos_attck);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 113, 20));
        lineEdit_2 = new QLineEdit(dos_attck);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 20, 41, 20));
        pushButton = new QPushButton(dos_attck);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 20, 80, 20));
        pushButton_2 = new QPushButton(dos_attck);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 70, 80, 20));
        pushButton_3 = new QPushButton(dos_attck);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 20, 80, 20));
        pushButton_4 = new QPushButton(dos_attck);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 70, 80, 20));
        label = new QLabel(dos_attck);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(23, 70, 101, 20));
        label_2 = new QLabel(dos_attck);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 70, 54, 20));

        retranslateUi(dos_attck);

        QMetaObject::connectSlotsByName(dos_attck);
    } // setupUi

    void retranslateUi(QWidget *dos_attck)
    {
        dos_attck->setWindowTitle(QCoreApplication::translate("dos_attck", "Form", nullptr));
        lineEdit->setText(QCoreApplication::translate("dos_attck", "148.70.205.134", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("dos_attck", "8009", nullptr));
        pushButton->setText(QCoreApplication::translate("dos_attck", "dos\346\224\273\345\207\273", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dos_attck", "\344\273\277ddos\346\224\273\345\207\273", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dos_attck", "dos\346\224\273\345\207\273\346\232\202\345\201\234", nullptr));
        pushButton_4->setText(QCoreApplication::translate("dos_attck", "\344\273\277ddos\346\224\273\345\207\273\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("dos_attck", "\345\217\221\351\200\201\345\214\205\347\232\204\346\225\260\351\207\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("dos_attck", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dos_attck: public Ui_dos_attck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOS_ATTCK_H
