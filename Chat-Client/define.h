#ifndef DEFINE_H
#define DEFINE_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <vector>
#include <QDataStream>
#include <QDateTime>
#include <QVector>
#include <QString>
#include <QObject>
#include <QMessageBox>
#include <QtSql>
#include <qsqlquery.h>

char *MyOwnQStringToChar(QString);

enum MessageType{
    Message,
    NewParticipant,
    ParticipantLeft,
    FileName,
    Refuse,
    AskStartChat,
    StartChat,
    RefuseChat
    ,RefuseFriend,AskAddFriend,BeFrineds,DeleteFriend
};

#endif // DEFINE_H
