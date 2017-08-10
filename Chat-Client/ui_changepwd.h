/********************************************************************************
** Form generated from reading UI file 'changepwd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPWD_H
#define UI_CHANGEPWD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changepwd
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *changepwd)
    {
        if (changepwd->objectName().isEmpty())
            changepwd->setObjectName(QString::fromUtf8("changepwd"));
        changepwd->resize(400, 186);
        label = new QLabel(changepwd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 81, 31));
        label_3 = new QLabel(changepwd);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 60, 41, 31));
        lineEdit_2 = new QLineEdit(changepwd);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 110, 161, 33));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(changepwd);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 110, 71, 31));
        pushButton = new QPushButton(changepwd);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 80, 71, 31));
        lineEdit = new QLineEdit(changepwd);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 60, 161, 33));
        lineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(changepwd);

        QMetaObject::connectSlotsByName(changepwd);
    } // setupUi

    void retranslateUi(QWidget *changepwd)
    {
        changepwd->setWindowTitle(QApplication::translate("changepwd", "ChangePWD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("changepwd", "NULL", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("changepwd", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("changepwd", "\351\207\215\345\244\215\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("changepwd", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class changepwd: public Ui_changepwd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPWD_H
