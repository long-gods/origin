/********************************************************************************
** Form generated from reading UI file 'snmpscanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNMPSCANNER_H
#define UI_SNMPSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_snmpscanner
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTreeView *treeView;

    void setupUi(QWidget *snmpscanner)
    {
        if (snmpscanner->objectName().isEmpty())
            snmpscanner->setObjectName(QString::fromUtf8("snmpscanner"));
        snmpscanner->resize(400, 300);
        lineEdit = new QLineEdit(snmpscanner);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 30, 113, 20));
        pushButton = new QPushButton(snmpscanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 30, 51, 20));
        treeView = new QTreeView(snmpscanner);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 70, 256, 192));

        retranslateUi(snmpscanner);

        QMetaObject::connectSlotsByName(snmpscanner);
    } // setupUi

    void retranslateUi(QWidget *snmpscanner)
    {
        snmpscanner->setWindowTitle(QCoreApplication::translate("snmpscanner", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("snmpscanner", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class snmpscanner: public Ui_snmpscanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNMPSCANNER_H
