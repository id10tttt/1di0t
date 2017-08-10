/********************************************************************************
** Form generated from reading UI file 'filesend.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESEND_H
#define UI_FILESEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_filesend
{
public:
    QProgressBar *progressBar;
    QPushButton *btnQuit;
    QLabel *serverStatusLabel;

    void setupUi(QDialog *filesend)
    {
        if (filesend->objectName().isEmpty())
            filesend->setObjectName(QString::fromUtf8("filesend"));
        filesend->resize(400, 300);
        progressBar = new QProgressBar(filesend);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 140, 301, 23));
        progressBar->setValue(0);
        btnQuit = new QPushButton(filesend);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setGeometry(QRect(160, 200, 75, 23));
        serverStatusLabel = new QLabel(filesend);
        serverStatusLabel->setObjectName(QString::fromUtf8("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(60, 60, 281, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(filesend);

        QMetaObject::connectSlotsByName(filesend);
    } // setupUi

    void retranslateUi(QDialog *filesend)
    {
        filesend->setWindowTitle(QApplication::translate("filesend", "FIleSend", 0, QApplication::UnicodeUTF8));
        btnQuit->setText(QApplication::translate("filesend", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        serverStatusLabel->setText(QApplication::translate("filesend", "\346\226\207\344\273\266\344\274\240\350\276\223\344\270\255...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class filesend: public Ui_filesend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESEND_H
