/********************************************************************************
** Form generated from reading UI file 'webtest.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBTEST_H
#define UI_WEBTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_webtest
{
public:

    void setupUi(QWidget *webtest)
    {
        if (webtest->objectName().isEmpty())
            webtest->setObjectName(QString::fromUtf8("webtest"));
        webtest->resize(589, 378);

        retranslateUi(webtest);

        QMetaObject::connectSlotsByName(webtest);
    } // setupUi

    void retranslateUi(QWidget *webtest)
    {
        webtest->setWindowTitle(QCoreApplication::translate("webtest", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class webtest: public Ui_webtest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBTEST_H
