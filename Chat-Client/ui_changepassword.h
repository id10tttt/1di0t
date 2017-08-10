/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

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

class Ui_changepassword
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *changepassword)
    {
        if (changepassword->objectName().isEmpty())
            changepassword->setObjectName(QString::fromUtf8("changepassword"));
        changepassword->resize(400, 198);
        label = new QLabel(changepassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 81, 31));
        lineEdit = new QLineEdit(changepassword);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 60, 161, 33));
        label_2 = new QLabel(changepassword);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 110, 71, 31));
        lineEdit_2 = new QLineEdit(changepassword);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 110, 161, 33));
        pushButton = new QPushButton(changepassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 80, 71, 31));
        label_3 = new QLabel(changepassword);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 60, 41, 31));

        retranslateUi(changepassword);

        QMetaObject::connectSlotsByName(changepassword);
    } // setupUi

    void retranslateUi(QDialog *changepassword)
    {
        changepassword->setWindowTitle(QApplication::translate("changepassword", "ChangePassword", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("changepassword", "NULL", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("changepassword", "\351\207\215\345\244\215\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("changepassword", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("changepassword", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class changepassword: public Ui_changepassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
