/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <chi.h>
#include "titlebar.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    Titlebar *Title;
    QLabel *label;
    chi *widget;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(837, 673);
        Dialog->setMinimumSize(QSize(200, 0));
        Dialog->setLayoutDirection(Qt::LeftToRight);
        Dialog->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Title = new Titlebar(Dialog);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(9, 9, 819, 50));
        Title->setMinimumSize(QSize(0, 50));
        Title->setMaximumSize(QSize(16777215, 50));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 65, 120, 50));
        label->setMinimumSize(QSize(120, 50));
        label->setMaximumSize(QSize(120, 50));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";\n"
"\n"
""));
        widget = new chi(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 121, 819, 250));
        widget->setMinimumSize(QSize(47, 229));
        widget->setMaximumSize(QSize(16777215, 250));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 520, 71, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(650, 580, 101, 31));
        pushButton_2->setStyleSheet(QLatin1String("  border:2px groove gray;\n"
"background-color: rgb(58, 115, 255);\n"
"  border-radius:10px;\n"
"  padding:2px 4px;"));
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(false);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 470, 71, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 470, 221, 31));
        comboBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(Dialog);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 520, 221, 31));
        comboBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 580, 71, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 580, 431, 31));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 420, 441, 31));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 420, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 580, 31, 31));
        pushButton->setFlat(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#00aaff;\">\350\276\223\345\207\272\344\270\272\345\233\276\347\211\207</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\346\240\274\345\274\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "\350\276\223\345\207\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\345\233\276\347\211\207\345\223\201\350\264\250", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
         << QApplication::translate("Dialog", "\350\266\205\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
         << QApplication::translate("Dialog", "\347\273\210\346\236\201\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "PNG", Q_NULLPTR)
         << QApplication::translate("Dialog", "JPG", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Dialog", "\344\277\235\345\255\230\345\210\260", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Dialog", "D;\\", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Dialog", "\344\277\235\345\257\206\357\274\214\344\270\245\347\246\201\345\244\215\345\210\266\357\274\214\345\216\237\344\273\266\357\274\214\346\240\267\344\273\266", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "\346\260\264\345\215\260\345\206\205\345\256\271", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
