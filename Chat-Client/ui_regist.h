/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

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

class Ui_regist
{
public:
    QLabel *label_6;
    QLineEdit *username;
    QLineEdit *phone;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *password;
    QLineEdit *question;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *realname;
    QLineEdit *repetpassword;
    QLineEdit *sex;
    QLineEdit *answer;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *regist)
    {
        if (regist->objectName().isEmpty())
            regist->setObjectName(QString::fromUtf8("regist"));
        regist->resize(528, 384);
        QFont font;
        font.setPointSize(12);
        regist->setFont(font);
        label_6 = new QLabel(regist);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 200, 66, 31));
        username = new QLineEdit(regist);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(110, 60, 131, 33));
        phone = new QLineEdit(regist);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(350, 200, 141, 33));
        label = new QLabel(regist);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 66, 31));
        label_3 = new QLabel(regist);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 60, 66, 31));
        password = new QLineEdit(regist);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 130, 131, 33));
        password->setEchoMode(QLineEdit::Password);
        question = new QLineEdit(regist);
        question->setObjectName(QString::fromUtf8("question"));
        question->setGeometry(QRect(110, 270, 131, 33));
        label_5 = new QLabel(regist);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 200, 66, 31));
        label_2 = new QLabel(regist);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 130, 66, 31));
        label_4 = new QLabel(regist);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 130, 66, 31));
        realname = new QLineEdit(regist);
        realname->setObjectName(QString::fromUtf8("realname"));
        realname->setGeometry(QRect(350, 60, 141, 33));
        repetpassword = new QLineEdit(regist);
        repetpassword->setObjectName(QString::fromUtf8("repetpassword"));
        repetpassword->setGeometry(QRect(350, 130, 141, 33));
        repetpassword->setEchoMode(QLineEdit::Password);
        sex = new QLineEdit(regist);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(110, 200, 131, 33));
        answer = new QLineEdit(regist);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setGeometry(QRect(350, 270, 141, 33));
        label_7 = new QLabel(regist);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 270, 66, 31));
        label_8 = new QLabel(regist);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 270, 66, 31));
        pushButton = new QPushButton(regist);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 330, 95, 31));
        pushButton_2 = new QPushButton(regist);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 330, 95, 31));

        retranslateUi(regist);

        QMetaObject::connectSlotsByName(regist);
    } // setupUi

    void retranslateUi(QDialog *regist)
    {
        regist->setWindowTitle(QApplication::translate("regist", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("regist", "\347\224\265\350\257\235", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("regist", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("regist", "\347\234\237\345\256\236\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("regist", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("regist", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("regist", "\351\207\215\345\244\215\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("regist", "\351\227\256\351\242\230\347\255\224\346\241\210", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("regist", "\345\257\206\344\277\235\351\227\256\351\242\230", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("regist", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("regist", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class regist: public Ui_regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
