#ifndef WIDGT_H
#define WIDGT_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "chatwidgit.h"
#include "filesend.h"
#include <qmap.h>
#include "define.h"

namespace Ui {
    class Widgt;
}



class Widgt : public QWidget
{
    Q_OBJECT

public:
    explicit Widgt(QWidget *parent = 0);
    ~Widgt();

    QString getUserName();

    void SetName(QString);

    QModelIndex demo;


protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);
    void sendMessage(MessageType type,QString serverAddress="",QString message = "");
    void newParticipant(QString localHostName,QString ipAddress);
    void participantLeft(QString localHostName,QString time);
    void hasPendingFile(QString localhostname,QString serverAddress,
                        QString clientAddress,QString fileName);


private:

    QString Name;
    Ui::Widgt *ui;
    QUdpSocket *udpSocket;
    QMap<QString,ChatWidgit *> list;
    qint16 port;
    filesend * Sender;

    QMenu *m_menu;

    QString getIP();

    void creatMenu(/*const QList<QString> *groutList*/);

private slots:
    void on_btnAll_clicked();

    void on_tableWidget_2_doubleClicked(QModelIndex index);
    void sendMessageToFriend();
    void addfri();
    void userinformation();
    void deletefri();
    void synclist();

    void closeFromChat(QString);
    void sendMessagesToMain(QString,QString);
    void processPendingDatagrams();
    void sentFileName(QString,QString);
    void hasFileToSend(QString,QString);

//    void onClickRightButton();
//    void onDoubleClickFriendButton(QModelIndex index);

    void recvdata(QString data);
    void recvkeydata(QString data);

//    void on_tableWidget_2_pressed(const QModelIndex &index);


signals:
    void sendMessagesZ(QString address,QString first,QString second);
    void senddata(QString ipaddress,QString name);
    void senduserinfo(QString username,QString realname,QString sex,QString phone,QString registime);
};

#endif // Widgt_H

