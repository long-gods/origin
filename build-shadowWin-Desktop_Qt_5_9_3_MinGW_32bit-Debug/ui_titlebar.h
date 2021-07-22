/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Titlebar
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clostBtn;

    void setupUi(QWidget *Titlebar)
    {
        if (Titlebar->objectName().isEmpty())
            Titlebar->setObjectName(QStringLiteral("Titlebar"));
        Titlebar->setWindowModality(Qt::NonModal);
        Titlebar->resize(402, 42);
        Titlebar->setMinimumSize(QSize(0, 30));
        Titlebar->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(Titlebar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clostBtn = new QPushButton(Titlebar);
        clostBtn->setObjectName(QStringLiteral("clostBtn"));
        clostBtn->setMinimumSize(QSize(24, 24));
        clostBtn->setMaximumSize(QSize(24, 24));
        clostBtn->setFlat(true);

        horizontalLayout->addWidget(clostBtn);


        retranslateUi(Titlebar);

        QMetaObject::connectSlotsByName(Titlebar);
    } // setupUi

    void retranslateUi(QWidget *Titlebar)
    {
        Titlebar->setWindowTitle(QApplication::translate("Titlebar", "Form", Q_NULLPTR));
        clostBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Titlebar: public Ui_Titlebar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
