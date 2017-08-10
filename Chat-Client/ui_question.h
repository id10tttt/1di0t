/********************************************************************************
** Form generated from reading UI file 'question.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTION_H
#define UI_QUESTION_H

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

class Ui_question
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *username;
    QLabel *label_4;

    void setupUi(QDialog *question)
    {
        if (question->objectName().isEmpty())
            question->setObjectName(QString::fromUtf8("question"));
        question->resize(337, 192);
        pushButton = new QPushButton(question);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 150, 95, 31));
        lineEdit = new QLineEdit(question);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 100, 191, 33));
        label = new QLabel(question);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 71, 31));
        label_2 = new QLabel(question);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 71, 31));
        label_3 = new QLabel(question);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 66, 31));
        pushButton_2 = new QPushButton(question);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 150, 95, 31));
        username = new QLabel(question);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(100, 20, 191, 31));
        label_4 = new QLabel(question);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 60, 191, 31));

        retranslateUi(question);

        QMetaObject::connectSlotsByName(question);
    } // setupUi

    void retranslateUi(QDialog *question)
    {
        question->setWindowTitle(QApplication::translate("question", "Question&Answer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("question", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("question", "Answer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("question", "Question", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("question", "Username", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("question", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        username->setText(QApplication::translate("question", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("question", "NULL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class question: public Ui_question {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTION_H
