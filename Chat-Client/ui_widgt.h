/********************************************************************************
** Form generated from reading UI file 'widgt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGT_H
#define UI_WIDGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widgt
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lbOnline;
    QPushButton *btnAll;
    QLabel *label;
    QLabel *usernamelabel;

    void setupUi(QWidget *Widgt)
    {
        if (Widgt->objectName().isEmpty())
            Widgt->setObjectName(QString::fromUtf8("Widgt"));
        Widgt->resize(345, 511);
        layoutWidget = new QWidget(Widgt);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 341, 451));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget_2 = new QTableWidget(layoutWidget);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(tableWidget_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbOnline = new QLabel(layoutWidget);
        lbOnline->setObjectName(QString::fromUtf8("lbOnline"));

        horizontalLayout->addWidget(lbOnline);

        btnAll = new QPushButton(layoutWidget);
        btnAll->setObjectName(QString::fromUtf8("btnAll"));

        horizontalLayout->addWidget(btnAll);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        label = new QLabel(Widgt);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 21));
        usernamelabel = new QLabel(Widgt);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));
        usernamelabel->setGeometry(QRect(100, 10, 71, 21));

        retranslateUi(Widgt);

        QMetaObject::connectSlotsByName(Widgt);
    } // setupUi

    void retranslateUi(QWidget *Widgt)
    {
        Widgt->setWindowTitle(QApplication::translate("Widgt", "Chat", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widgt", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widgt", "IP Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widgt", "Friend", 0, QApplication::UnicodeUTF8));
        lbOnline->setText(QApplication::translate("Widgt", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", 0, QApplication::UnicodeUTF8));
        btnAll->setText(QApplication::translate("Widgt", "\347\276\244\350\201\212", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widgt", "Username:", 0, QApplication::UnicodeUTF8));
        usernamelabel->setText(QApplication::translate("Widgt", "NULL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widgt: public Ui_Widgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGT_H
