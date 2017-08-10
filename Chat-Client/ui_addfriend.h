/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addfriend
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *addfriend)
    {
        if (addfriend->objectName().isEmpty())
            addfriend->setObjectName(QString::fromUtf8("addfriend"));
        addfriend->resize(377, 158);
        label = new QLabel(addfriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 66, 31));
        lineEdit = new QLineEdit(addfriend);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 40, 113, 33));
        pushButton = new QPushButton(addfriend);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 110, 95, 31));

        retranslateUi(addfriend);

        QMetaObject::connectSlotsByName(addfriend);
    } // setupUi

    void retranslateUi(QDialog *addfriend)
    {
        addfriend->setWindowTitle(QApplication::translate("addfriend", "\346\267\273\345\212\240\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("addfriend", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("addfriend", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class addfriend: public Ui_addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
