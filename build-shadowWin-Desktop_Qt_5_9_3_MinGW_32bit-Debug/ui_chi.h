/********************************************************************************
** Form generated from reading UI file 'chi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHI_H
#define UI_CHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chi
{
public:
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;

    void setupUi(QWidget *chi)
    {
        if (chi->objectName().isEmpty())
            chi->setObjectName(QStringLiteral("chi"));
        chi->resize(600, 373);
        radioButton_2 = new QRadioButton(chi);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(340, 20, 201, 151));
        radioButton_2->setLayoutDirection(Qt::LeftToRight);
        radioButton_2->setAutoFillBackground(false);
        radioButton_2->setStyleSheet(QLatin1String("QRadioButton::indicator { \n"
"    width: 0px; \n"
"    height: 0px; \n"
"} "));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/image/normalqualityitem.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/res/image/watermarkitemclick.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral(":/res/image/watermarkitemclick.png"), QSize(), QIcon::Selected, QIcon::On);
        radioButton_2->setIcon(icon);
        radioButton_2->setIconSize(QSize(194, 145));
        radioButton_2->setCheckable(true);
        radioButton_2->setChecked(false);
        radioButton_2->setAutoRepeat(false);
        radioButton = new QRadioButton(chi);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(60, 20, 201, 151));
        radioButton->setStyleSheet(QLatin1String("QRadioButton::indicator { \n"
"    width: 0px; \n"
"    height: 0px; \n"
"} "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/image/nowatermarkitem.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon1);
        radioButton->setIconSize(QSize(201, 151));

        retranslateUi(chi);

        QMetaObject::connectSlotsByName(chi);
    } // setupUi

    void retranslateUi(QWidget *chi)
    {
        chi->setWindowTitle(QApplication::translate("chi", "Form", Q_NULLPTR));
        radioButton_2->setText(QString());
        radioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chi: public Ui_chi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHI_H
