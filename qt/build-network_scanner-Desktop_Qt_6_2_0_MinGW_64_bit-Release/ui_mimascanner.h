/********************************************************************************
** Form generated from reading UI file 'mimascanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIMASCANNER_H
#define UI_MIMASCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mimascanner
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label_3;

    void setupUi(QWidget *mimascanner)
    {
        if (mimascanner->objectName().isEmpty())
            mimascanner->setObjectName(QString::fromUtf8("mimascanner"));
        mimascanner->resize(553, 369);
        lineEdit = new QLineEdit(mimascanner);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 110, 113, 20));
        label = new QLabel(mimascanner);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 110, 54, 12));
        label_2 = new QLabel(mimascanner);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 61, 16));
        comboBox = new QComboBox(mimascanner);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 80, 181, 22));
        pushButton = new QPushButton(mimascanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 80, 80, 20));
        pushButton_2 = new QPushButton(mimascanner);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 140, 80, 20));
        label_4 = new QLabel(mimascanner);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 140, 54, 12));
        lineEdit_3 = new QLineEdit(mimascanner);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 140, 113, 20));
        lineEdit_2 = new QLineEdit(mimascanner);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 40, 113, 20));
        label_3 = new QLabel(mimascanner);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 54, 12));

        retranslateUi(mimascanner);

        QMetaObject::connectSlotsByName(mimascanner);
    } // setupUi

    void retranslateUi(QWidget *mimascanner)
    {
        mimascanner->setWindowTitle(QCoreApplication::translate("mimascanner", "\345\274\261\345\257\206\347\240\201\346\211\253\346\217\217", nullptr));
        lineEdit->setText(QCoreApplication::translate("mimascanner", "admin", nullptr));
        label->setText(QCoreApplication::translate("mimascanner", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("mimascanner", "\345\257\206\347\240\201\346\234\254\346\226\207\344\273\266", nullptr));
        pushButton->setText(QCoreApplication::translate("mimascanner", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mimascanner", "ftp\347\210\206\347\240\264", nullptr));
        label_4->setText(QCoreApplication::translate("mimascanner", "\346\265\213\350\257\225\345\257\206\347\240\201", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_2->setText(QCoreApplication::translate("mimascanner", "192.168.1.128", nullptr));
        label_3->setText(QCoreApplication::translate("mimascanner", "ip\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mimascanner: public Ui_mimascanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIMASCANNER_H
