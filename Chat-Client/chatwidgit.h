#ifndef CHATWIDGIT_H
#define CHATWIDGIT_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "filesend.h"
#include "filereceive.h"
//#include "taesclass.h"

namespace Ui {
    class ChatWidgit;
}

class ChatWidgit : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidgit(QWidget *parent = 0);
    ~ChatWidgit();
    QString getSecAddr();
    void setSecAddr(QString,QString);



private:
    QFile saveFile;
    QString secretAddress;
    Ui::ChatWidgit *ui;
    QString getIP();
    void closeEvent(QCloseEvent *);

    QColor color;

    bool eventFilter(QObject *target, QEvent *event);
private slots:

    void on_textHistory_clicked();
    void on_textSave_clicked();
    void on_textBin_clicked();
    void on_btnSend_clicked();
    void setMessage(QString address,QString first,QString second);


    void on_btnClose_clicked();

//    void on_toolButton_clicked();

signals:
    void sendMessagesFromChat(QString ,QString);
    void closeChat(QString);
    void sendFile(QString,QString);
};


#endif // CHATWIDGIT_H
