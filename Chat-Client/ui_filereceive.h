/********************************************************************************
** Form generated from reading UI file 'filereceive.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECEIVE_H
#define UI_FILERECEIVE_H

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

class Ui_filereceive
{
public:
    QPushButton *btnClose;
    QPushButton *btnCancel;
    QLabel *FileReceiverStatusLabel;
    QProgressBar *progressBar;

    void setupUi(QDialog *filereceive)
    {
        if (filereceive->objectName().isEmpty())
            filereceive->setObjectName(QString::fromUtf8("filereceive"));
        filereceive->resize(400, 300);
        btnClose = new QPushButton(filereceive);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(210, 200, 75, 23));
        btnCancel = new QPushButton(filereceive);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(100, 200, 75, 23));
        FileReceiverStatusLabel = new QLabel(filereceive);
        FileReceiverStatusLabel->setObjectName(QString::fromUtf8("FileReceiverStatusLabel"));
        FileReceiverStatusLabel->setGeometry(QRect(40, 60, 321, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        FileReceiverStatusLabel->setFont(font);
        FileReceiverStatusLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(filereceive);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 140, 311, 23));
        progressBar->setValue(0);

        retranslateUi(filereceive);

        QMetaObject::connectSlotsByName(filereceive);
    } // setupUi

    void retranslateUi(QDialog *filereceive)
    {
        filereceive->setWindowTitle(QApplication::translate("filereceive", "FIleReceive", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("filereceive", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("filereceive", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        FileReceiverStatusLabel->setText(QApplication::translate("filereceive", "\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266... ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class filereceive: public Ui_filereceive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECEIVE_H
