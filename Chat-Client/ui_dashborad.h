/********************************************************************************
** Form generated from reading UI file 'dashborad.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBORAD_H
#define UI_DASHBORAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dashborad
{
public:
    QPushButton *pushButton;
    QLabel *onlinepeople;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;

    void setupUi(QDialog *dashborad)
    {
        if (dashborad->objectName().isEmpty())
            dashborad->setObjectName(QString::fromUtf8("dashborad"));
        dashborad->resize(269, 457);
        pushButton = new QPushButton(dashborad);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 420, 95, 31));
        onlinepeople = new QLabel(dashborad);
        onlinepeople->setObjectName(QString::fromUtf8("onlinepeople"));
        onlinepeople->setGeometry(QRect(10, 420, 66, 21));
        tableWidget = new QTableWidget(dashborad);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/User.png"), QSize(), QIcon::Normal, QIcon::On);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 50, 271, 361));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pushButton_2 = new QPushButton(dashborad);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 420, 61, 31));

        retranslateUi(dashborad);

        QMetaObject::connectSlotsByName(dashborad);
    } // setupUi

    void retranslateUi(QDialog *dashborad)
    {
        dashborad->setWindowTitle(QApplication::translate("dashborad", "ClientDashBorad", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dashborad", "\346\267\273\345\212\240\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        onlinepeople->setText(QApplication::translate("dashborad", "TextLabel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dashborad", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dashborad", "IP Address......", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dashborad", "\347\276\244\350\201\212", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dashborad: public Ui_dashborad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBORAD_H
