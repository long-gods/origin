/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(879, 300);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 81, 31));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 71, 21));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 71, 31));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 180, 71, 21));
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 20, 441, 31));
        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 70, 221, 31));
        comboBox_2 = new QComboBox(Form);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 120, 221, 31));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 180, 431, 31));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 180, 31, 31));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(650, 180, 101, 31));
        pushButton_2->setStyleSheet(QLatin1String("  border:2px groove gray;\n"
"background-color: rgb(85, 170, 255);\n"
"  border-radius:10px;\n"
"  padding:2px 4px;"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\346\260\264\345\215\260\345\206\205\345\256\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\345\233\276\347\211\207\345\223\201\350\264\250", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "\346\240\274\345\274\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "\344\277\235\345\255\230\345\210\260", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
         << QApplication::translate("Form", "\350\266\205\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
         << QApplication::translate("Form", "\347\273\210\346\236\201\351\253\230\346\270\205\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Form", "PNG", Q_NULLPTR)
         << QApplication::translate("Form", "JPG", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Form", "...", Q_NULLPTR));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
