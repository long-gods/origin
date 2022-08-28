/********************************************************************************
** Form generated from reading UI file 'netbiosscanner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETBIOSSCANNER_H
#define UI_NETBIOSSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetBiosscanner
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTreeView *treeView;

    void setupUi(QWidget *NetBiosscanner)
    {
        if (NetBiosscanner->objectName().isEmpty())
            NetBiosscanner->setObjectName(QString::fromUtf8("NetBiosscanner"));
        NetBiosscanner->resize(400, 300);
        pushButton = new QPushButton(NetBiosscanner);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 30, 51, 20));
        lineEdit = new QLineEdit(NetBiosscanner);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 30, 113, 20));
        treeView = new QTreeView(NetBiosscanner);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 70, 256, 192));

        retranslateUi(NetBiosscanner);

        QMetaObject::connectSlotsByName(NetBiosscanner);
    } // setupUi

    void retranslateUi(QWidget *NetBiosscanner)
    {
        NetBiosscanner->setWindowTitle(QCoreApplication::translate("NetBiosscanner", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("NetBiosscanner", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetBiosscanner: public Ui_NetBiosscanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETBIOSSCANNER_H
