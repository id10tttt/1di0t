/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfo
{
public:
    QLabel *label;
    QLabel *username;
    QLabel *label_2;
    QLabel *realname;
    QLabel *label_3;
    QLabel *sex;
    QLabel *label_4;
    QLabel *phone;
    QLabel *label_6;
    QLabel *registime;

    void setupUi(QWidget *userinfo)
    {
        if (userinfo->objectName().isEmpty())
            userinfo->setObjectName(QString::fromUtf8("userinfo"));
        userinfo->resize(340, 259);
        label = new QLabel(userinfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 81, 21));
        username = new QLabel(userinfo);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(130, 40, 171, 21));
        label_2 = new QLabel(userinfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 81, 21));
        realname = new QLabel(userinfo);
        realname->setObjectName(QString::fromUtf8("realname"));
        realname->setGeometry(QRect(130, 80, 171, 21));
        label_3 = new QLabel(userinfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 81, 21));
        sex = new QLabel(userinfo);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(130, 120, 171, 21));
        label_4 = new QLabel(userinfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 160, 81, 21));
        phone = new QLabel(userinfo);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(130, 160, 171, 21));
        label_6 = new QLabel(userinfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 200, 81, 21));
        registime = new QLabel(userinfo);
        registime->setObjectName(QString::fromUtf8("registime"));
        registime->setGeometry(QRect(130, 200, 171, 21));

        retranslateUi(userinfo);

        QMetaObject::connectSlotsByName(userinfo);
    } // setupUi

    void retranslateUi(QWidget *userinfo)
    {
        userinfo->setWindowTitle(QApplication::translate("userinfo", "UserInformation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("userinfo", "Username:", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("userinfo", "NULL", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("userinfo", "Realname:", 0, QApplication::UnicodeUTF8));
        realname->setText(QApplication::translate("userinfo", "NULL", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("userinfo", "Sex:", 0, QApplication::UnicodeUTF8));
        sex->setText(QApplication::translate("userinfo", "NULL", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("userinfo", "Phone:", 0, QApplication::UnicodeUTF8));
        phone->setText(QApplication::translate("userinfo", "NULL", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("userinfo", "Registime:", 0, QApplication::UnicodeUTF8));
        registime->setText(QApplication::translate("userinfo", "NULL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class userinfo: public Ui_userinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
