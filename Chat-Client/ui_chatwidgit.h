/********************************************************************************
** Form generated from reading UI file 'chatwidgit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGIT_H
#define UI_CHATWIDGIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidgit
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QTextBrowser *tbHistory;
    QGridLayout *gridLayout;
    QTextEdit *teEdit;
    QTextBrowser *tbShow;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *secretKey;
    QToolButton *textSave;
    QToolButton *textBin;
    QToolButton *textHistory;
    QHBoxLayout *horizontalLayout;
    QLabel *lbConn;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QPushButton *btnSend;

    void setupUi(QWidget *ChatWidgit)
    {
        if (ChatWidgit->objectName().isEmpty())
            ChatWidgit->setObjectName(QString::fromUtf8("ChatWidgit"));
        ChatWidgit->resize(678, 486);
        layoutWidget = new QWidget(ChatWidgit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 660, 473));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tbHistory = new QTextBrowser(layoutWidget);
        tbHistory->setObjectName(QString::fromUtf8("tbHistory"));

        gridLayout_2->addWidget(tbHistory, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        teEdit = new QTextEdit(layoutWidget);
        teEdit->setObjectName(QString::fromUtf8("teEdit"));
        teEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(teEdit->sizePolicy().hasHeightForWidth());
        teEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(teEdit, 2, 0, 1, 1);

        tbShow = new QTextBrowser(layoutWidget);
        tbShow->setObjectName(QString::fromUtf8("tbShow"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(tbShow->sizePolicy().hasHeightForWidth());
        tbShow->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tbShow, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        secretKey = new QLineEdit(layoutWidget);
        secretKey->setObjectName(QString::fromUtf8("secretKey"));

        horizontalLayout_2->addWidget(secretKey);

        textSave = new QToolButton(layoutWidget);
        textSave->setObjectName(QString::fromUtf8("textSave"));
        textSave->setAutoRaise(true);

        horizontalLayout_2->addWidget(textSave);

        textBin = new QToolButton(layoutWidget);
        textBin->setObjectName(QString::fromUtf8("textBin"));
        textBin->setAutoRaise(true);

        horizontalLayout_2->addWidget(textBin);

        textHistory = new QToolButton(layoutWidget);
        textHistory->setObjectName(QString::fromUtf8("textHistory"));
        textHistory->setAutoRaise(true);

        horizontalLayout_2->addWidget(textHistory);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbConn = new QLabel(layoutWidget);
        lbConn->setObjectName(QString::fromUtf8("lbConn"));

        horizontalLayout->addWidget(lbConn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        btnSend = new QPushButton(layoutWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        horizontalLayout->addWidget(btnSend);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ChatWidgit);

        QMetaObject::connectSlotsByName(ChatWidgit);
    } // setupUi

    void retranslateUi(QWidget *ChatWidgit)
    {
        ChatWidgit->setWindowTitle(QApplication::translate("ChatWidgit", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChatWidgit", "Key:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textSave->setToolTip(QApplication::translate("ChatWidgit", "\344\274\240\350\276\223\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textSave->setText(QApplication::translate("ChatWidgit", "files", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textBin->setToolTip(QApplication::translate("ChatWidgit", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textBin->setText(QApplication::translate("ChatWidgit", "clear", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textHistory->setToolTip(QApplication::translate("ChatWidgit", "\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textHistory->setText(QApplication::translate("ChatWidgit", "history", 0, QApplication::UnicodeUTF8));
        lbConn->setText(QApplication::translate("ChatWidgit", "\345\257\271\346\226\271ip\357\274\232xxx.xxx.xxx.xxx", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("ChatWidgit", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        btnSend->setText(QApplication::translate("ChatWidgit", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChatWidgit: public Ui_ChatWidgit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGIT_H
