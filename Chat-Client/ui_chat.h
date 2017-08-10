/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QTextBrowser *tbShow;
    QPushButton *btnSend;
    QTextEdit *teEdit;
    QToolButton *textSave;
    QToolButton *textBin;
    QToolButton *textHistory;
    QPushButton *btnClose;
    QLabel *lbConn;
    QTextBrowser *thistory;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(802, 454);
        tbShow = new QTextBrowser(chat);
        tbShow->setObjectName(QString::fromUtf8("tbShow"));
        tbShow->setGeometry(QRect(10, 30, 571, 271));
        btnSend = new QPushButton(chat);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(470, 420, 95, 31));
        teEdit = new QTextEdit(chat);
        teEdit->setObjectName(QString::fromUtf8("teEdit"));
        teEdit->setGeometry(QRect(10, 340, 571, 75));
        textSave = new QToolButton(chat);
        textSave->setObjectName(QString::fromUtf8("textSave"));
        textSave->setGeometry(QRect(410, 310, 51, 21));
        textBin = new QToolButton(chat);
        textBin->setObjectName(QString::fromUtf8("textBin"));
        textBin->setGeometry(QRect(470, 310, 51, 21));
        textHistory = new QToolButton(chat);
        textHistory->setObjectName(QString::fromUtf8("textHistory"));
        textHistory->setGeometry(QRect(530, 309, 51, 21));
        btnClose = new QPushButton(chat);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(374, 420, 81, 31));
        lbConn = new QLabel(chat);
        lbConn->setObjectName(QString::fromUtf8("lbConn"));
        lbConn->setGeometry(QRect(10, 420, 131, 31));
        thistory = new QTextBrowser(chat);
        thistory->setObjectName(QString::fromUtf8("thistory"));
        thistory->setGeometry(QRect(585, 30, 211, 391));

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", 0, QApplication::UnicodeUTF8));
        btnSend->setText(QApplication::translate("chat", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        textSave->setText(QApplication::translate("chat", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        textBin->setText(QApplication::translate("chat", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        textHistory->setText(QApplication::translate("chat", "\345\216\206\345\217\262", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("chat", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        lbConn->setText(QApplication::translate("chat", "\345\257\271\346\226\271IP\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
