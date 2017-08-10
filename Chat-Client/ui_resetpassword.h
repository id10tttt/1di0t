/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

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

class Ui_resetpassword
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *resetpassword)
    {
        if (resetpassword->objectName().isEmpty())
            resetpassword->setObjectName(QString::fromUtf8("resetpassword"));
        resetpassword->resize(380, 194);
        lineEdit = new QLineEdit(resetpassword);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 131, 33));
        label = new QLabel(resetpassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 80, 66, 31));
        pushButton = new QPushButton(resetpassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 80, 95, 31));

        retranslateUi(resetpassword);

        QMetaObject::connectSlotsByName(resetpassword);
    } // setupUi

    void retranslateUi(QDialog *resetpassword)
    {
        resetpassword->setWindowTitle(QApplication::translate("resetpassword", "Reset", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("resetpassword", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("resetpassword", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class resetpassword: public Ui_resetpassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
