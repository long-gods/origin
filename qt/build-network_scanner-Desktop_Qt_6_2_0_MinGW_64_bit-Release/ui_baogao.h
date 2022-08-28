/********************************************************************************
** Form generated from reading UI file 'baogao.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAOGAO_H
#define UI_BAOGAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_baogao
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *baogao)
    {
        if (baogao->objectName().isEmpty())
            baogao->setObjectName(QString::fromUtf8("baogao"));
        baogao->resize(545, 390);
        pushButton = new QPushButton(baogao);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 80, 20));
        textBrowser = new QTextBrowser(baogao);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 331, 351));

        retranslateUi(baogao);

        QMetaObject::connectSlotsByName(baogao);
    } // setupUi

    void retranslateUi(QWidget *baogao)
    {
        baogao->setWindowTitle(QCoreApplication::translate("baogao", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("baogao", "\347\224\237\346\210\220\346\212\245\345\221\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class baogao: public Ui_baogao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAOGAO_H
