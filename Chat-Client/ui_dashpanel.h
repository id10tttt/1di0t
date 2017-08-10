/********************************************************************************
** Form generated from reading UI file 'dashpanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHPANEL_H
#define UI_DASHPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashpanel
{
public:
    QTableWidget *tableWidget_3;

    void setupUi(QWidget *dashpanel)
    {
        if (dashpanel->objectName().isEmpty())
            dashpanel->setObjectName(QString::fromUtf8("dashpanel"));
        dashpanel->resize(271, 447);
        tableWidget_3 = new QTableWidget(dashpanel);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget_3->rowCount() < 1)
            tableWidget_3->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem2);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(0, 0, 271, 451));
        tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(dashpanel);

        QMetaObject::connectSlotsByName(dashpanel);
    } // setupUi

    void retranslateUi(QWidget *dashpanel)
    {
        dashpanel->setWindowTitle(QApplication::translate("dashpanel", "Friends", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dashpanel", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dashpanel", "IP Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("dashpanel", "\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dashpanel: public Ui_dashpanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHPANEL_H
