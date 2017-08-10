/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_chatbox
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *chatbox)
    {
        if (chatbox->objectName().isEmpty())
            chatbox->setObjectName(QString::fromUtf8("chatbox"));
        chatbox->resize(581, 450);
        textBrowser = new QTextBrowser(chatbox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 561, 231));
        pushButton = new QPushButton(chatbox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 410, 95, 31));
        toolButton = new QToolButton(chatbox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(520, 290, 41, 29));
        toolButton_2 = new QToolButton(chatbox);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(10, 290, 101, 29));
        label = new QLabel(chatbox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 66, 21));
        textEdit = new QTextEdit(chatbox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 320, 551, 75));

        retranslateUi(chatbox);

        QMetaObject::connectSlotsByName(chatbox);
    } // setupUi

    void retranslateUi(QDialog *chatbox)
    {
        chatbox->setWindowTitle(QApplication::translate("chatbox", "ChatBox", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("chatbox", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("chatbox", "Clear", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("chatbox", "\345\217\221\351\200\201\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("chatbox", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chatbox: public Ui_chatbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
