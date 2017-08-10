#include "widgt.h"
#include "ui_widgt.h"
#include "addfriend.h"
#include "ui_addfriend.h"
#include "chatwidgit.h"
#include "database.h"
#include "userinfo.h"
#include "ui_userinfo.h"
#include <iostream>
//#include "taesclass.h"

using namespace std;

QString keycontent;
Widgt::Widgt(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widgt)
{
    ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_menu = NULL;

    Sender = new filesend(this);
    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket->bind(port,QUdpSocket::ShareAddress
                    | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    connect(Sender,SIGNAL(sendFileName(QString,QString)),this,SLOT(sentFileName(QString,QString)));


}


void Widgt::SetName(QString name)
{
    Name = name;
    sendMessage(NewParticipant);
}


void Widgt::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString localHostName,ipAddress,message,secretAddress;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType)
        {
        case RefuseChat:
            {
                in  >>localHostName >>ipAddress >> secretAddress;
                if(secretAddress == getIP())
                    QMessageBox::information(this,tr("Refuse"),tr("From（%1）'s %2  refuse your chat request").arg(ipAddress).arg(localHostName));
                break;
            }
        case StartChat:
            {
                in  >>localHostName >>ipAddress >> secretAddress;
                if(secretAddress == getIP())
                {
                    ChatWidgit *chatView = new ChatWidgit();
                    list.insert(ipAddress,chatView);
                    connect(chatView,SIGNAL(closeChat(QString)),this,SLOT(closeFromChat(QString)));
                    connect(this,SIGNAL(sendMessagesZ(QString,QString,QString)),chatView,SLOT(setMessage(QString,QString,QString)));
                    connect(chatView,SIGNAL(sendMessagesFromChat(QString,QString)),this,SLOT(sendMessagesToMain(QString,QString)));
                    connect(chatView,SIGNAL(sendFile(QString,QString)),this,SLOT(hasFileToSend(QString,QString)));

                    chatView->setSecAddr(ipAddress,Name);
                    chatView->show();
                }
                break;
            }
        case AskStartChat:

            in  >>localHostName >>ipAddress >> secretAddress;
            if(secretAddress == getIP())
            {
                int btn = QMessageBox::information(this,tr("Agree chat"),
                                                   tr("From %1(%2)'s chat,yes/no？")
                                                   .arg(ipAddress).arg(localHostName),
                                                   QMessageBox::Yes,QMessageBox::No);
                if(btn == QMessageBox::Yes)
                {
                    ChatWidgit *chatView = new ChatWidgit();
                    list.insert(ipAddress,chatView);
                    connect(chatView,SIGNAL(closeChat(QString)),this,SLOT(closeFromChat(QString)));
                    connect(this,SIGNAL(sendMessagesZ(QString,QString,QString)),chatView,SLOT(setMessage(QString,QString,QString)));
                    connect(chatView,SIGNAL(sendMessagesFromChat(QString,QString)),this,SLOT(sendMessagesToMain(QString,QString)));
                    connect(chatView,SIGNAL(sendFile(QString,QString)),this,SLOT(hasFileToSend(QString,QString)));

                    chatView->setSecAddr(ipAddress,Name);
                    chatView->show();
                    sendMessage(StartChat,ipAddress);
                }else if(btn == QMessageBox::No)
                {
                    sendMessage(RefuseChat,ipAddress);
                }
            }
            break;
        case Message:
            {
                in  >>localHostName >>ipAddress >> secretAddress >>message;

//                QMessageBox::information(this,tr("0"),tr("%1sec\n%2").arg(secretAddress).arg(ipAddress));
                if(secretAddress == getIP() )//发给自己的私有
                {
//                    QMessageBox::information(this,tr("0"),tr("%1sec").arg(secretAddress));
                    if(list.contains(ipAddress)){
                        list[ipAddress]->show();
                        emit sendMessagesZ(ipAddress,tr("[ %1 ] %2").arg(localHostName).arg(time),message);
                    }else{
                        ChatWidgit *chatView = new ChatWidgit();
                        list.insert(ipAddress,chatView);
                        connect(chatView,SIGNAL(senddata(QString)),this,SLOT(recvkeydata(QString)));
                        connect(chatView,SIGNAL(closeChat(QString)),this,SLOT(closeFromChat(QString)));
                        connect(this,SIGNAL(sendMessagesZ(QString,QString,QString)),chatView,SLOT(setMessage(QString,QString,QString)));
                        connect(chatView,SIGNAL(sendMessagesFromChat(QString,QString)),this,SLOT(sendMessagesToMain(QString,QString)));
                        connect(chatView,SIGNAL(sendFile(QString,QString)),this,SLOT(hasFileToSend(QString,QString)));

                        chatView->setSecAddr(ipAddress,Name);
                        chatView->show();

                        emit sendMessagesZ(ipAddress,tr("[ %1 ] %2").arg(localHostName).arg(time),message);
                    }
                }else if(secretAddress == "NULL")
                {
                    if(list.contains("NULL")){
                        list["NULL"]->show();
                        emit sendMessagesZ(secretAddress,tr("[ %1 ] %2").arg(localHostName).arg(time),message);
                    }else{
                        ChatWidgit *chatView = new ChatWidgit();
                        list.insert(secretAddress,chatView);
                        connect(chatView,SIGNAL(closeChat(QString)),this,SLOT(closeFromChat(QString)));
                        connect(this,SIGNAL(sendMessagesZ(QString,QString,QString)),chatView,SLOT(setMessage(QString,QString,QString)));
                        connect(chatView,SIGNAL(sendMessagesFromChat(QString,QString)),this,SLOT(sendMessagesToMain(QString,QString)));
                        connect(chatView,SIGNAL(sendFile(QString,QString)),this,SLOT(hasFileToSend(QString,QString)));

                        chatView->setSecAddr(secretAddress,Name);
                        chatView->show();
                        emit sendMessagesZ(secretAddress,tr("[ %1 ] %2").arg(localHostName).arg(time),message);
                    }
                }
                break;
            }
        case NewParticipant:
            {
                in  >>localHostName >>ipAddress;
                newParticipant(localHostName,ipAddress);
                break;
            }
        case ParticipantLeft:
            {
                in  >>localHostName;
                participantLeft(localHostName,time);
                break;
            }
        case FileName:
            {
                in  >>localHostName >> ipAddress;
                QString clientAddress,fileName;
                in >> clientAddress >> fileName;
                QMessageBox::information(this,tr(""),tr("%1ipaddr\n%2sev\n%3file").arg(ipAddress).arg(clientAddress).arg(message));
                hasPendingFile(localHostName,ipAddress,clientAddress,fileName);
                break;
            }
        case Refuse:
            {
                in  >> localHostName;
                QString serverAddress;
                in >> ipAddress >> serverAddress;

                if(getIP() == serverAddress)
                {
                    this->Sender->refused();
                }
                break;
            }
        case RefuseFriend:
        {
            in  >>localHostName >>ipAddress >> secretAddress;
            if(secretAddress == getIP())
                QMessageBox::information(this,tr("Refuse"),tr("From （%1）'s %2  refuse your ask friend request.").arg(ipAddress).arg(localHostName));
            break;
        }
        case AskAddFriend:
        {
            in  >>localHostName >>ipAddress >> secretAddress;
            if(secretAddress == getIP())
            {
                int btn = QMessageBox::information(this,tr("Agree add friend"),
                                                   tr("From %1(%2)'s add friend request,agree？")
                                                   .arg(ipAddress).arg(localHostName),
                                                   QMessageBox::Yes,QMessageBox::No);
                if(btn == QMessageBox::Yes)
                {
                    QSqlQuery query;
                    QString dbnameself;
                    if (!database::Open())
                    {
                        QMessageBox::about(0,tr("Failed"),tr("Failed to connect db."));
                        database::Close();
                        return ;
                    }
                    dbnameself = ui->usernamelabel->text();
                    QString inserter = "create table if not exists "+dbnameself+"friend(friendname char (40) not null);";
                    //QMessageBox::about(0,tr("QUERY STRINGS"),inserter);
                    query.exec(inserter);
                    std::cout << query.size() << endl;
                    if (!query.isActive())
                    {
                        QMessageBox::about(0,tr("Failed"),tr("Create table failed"));
                        database::Close();
                        return ;
                    }
                    if (query.size() == 0)
                    {
                        QMessageBox::about(0,tr("Warring!!!"),tr("Create table failed"));
                        database::Close();
                        return ;
                    }

                    inserter = "select * from "+dbnameself+"friend where friendname='"+localHostName+"'";
                    query.exec(inserter);
                    QMessageBox::about(0,tr("test"),inserter);
                    std::cout << query.size() << endl;
                    if (!query.isActive())
                    {
                        QMessageBox::about(0,tr("Failed"),tr("He/She has been your friend."));
                        database::Close();
                        return ;
                    }
                    if (query.size() != 0)
                    {
                        QMessageBox::about(0,tr("Warring!!!"),tr("He/She has been your friend."));
                        database::Close();
                        return ;
                    }
                    inserter = "insert into "+dbnameself+"friend(friendname) values('"+localHostName+"')";

                    query.exec(inserter);
                    if (!query.isActive())
                    {
                        QMessageBox::about(0,tr("Failed"),tr("Add friend in db failed"));
                        database::Close();
                        return ;
                    }
                    if (query.size() == 0)
                    {
                        QMessageBox::about(0,tr("Failed"),tr("Add friend in db failed"));
                        database::Close();
                        return ;
                    }
                    QMessageBox::about(0,tr("Success"),tr("Add friend success!"));
                    QString flagyes = "Yes";
//                    QTableWidgetItem *friends = new QTableWidgetItem(flagyes);
//                    ui->tableWidget_2->setItem(demo.row(),2,friends);

                    sendMessage(BeFrineds,ipAddress);
                }else if(btn == QMessageBox::No)
                {
                    sendMessage(RefuseFriend,ipAddress);
                }
            }
            break;
        }
        case BeFrineds:{
            in  >>localHostName >>ipAddress >> secretAddress;
//            QMessageBox::about(0,tr("localHostName"),localHostName);
//            QMessageBox::about(0,tr("ipAddress"),ipAddress);
//            QMessageBox::about(0,tr("secretAddress"),secretAddress);
//            return ;
            if (secretAddress == getIP()){
                QMessageBox::information(this,tr("Agree"),tr("From（%1）'s %2  agree to add you as friend.").arg(ipAddress).arg(localHostName));
                QString dbtablename = ui->usernamelabel->text();
                if (!database::Open())
                {
                    QMessageBox::about(0,tr("Fail"),tr("Failed to connect database."));
                    database::Close();
                    return ;
                }
                QSqlQuery query;
                QString inserter = "create table if not exists "+dbtablename+"friend(friendname char(40) not null);";
          //      QMessageBox::about(0,tr("create dbstring"),inserter);
          //      return ;
                query.exec(inserter);
                std::cout << query.size() << endl;
                if (!query.isActive())
                {
                    QMessageBox::about(0,tr("Failed"),tr("Create table failed"));
                    database::Close();
                    return ;
                }
                if (query.size() == 0)
                {
                    QMessageBox::about(0,tr("Warring!!!"),tr("Create table failed"));
                    database::Close();
                    return ;
                }

                inserter = "select * from "+dbtablename+"friend where friendname='"+localHostName+"'";
                query.exec(inserter);
//                QMessageBox::about(0,tr("query test"),inserter);
//                return ;
                std::cout << query.size() << endl;
//                return ;
                if (!query.isActive())
                {
                    QMessageBox::about(0,tr("Failed"),tr("He/She has been your friend."));
                    database::Close();
                    return ;
                }
                if (query.size() != 0)
                {
                    QMessageBox::about(0,tr("Failed"),tr("He/She has been your friend."));
                    database::Close();
                    return ;
                }

                inserter = "insert into "+dbtablename+"friend(friendname) values('"+localHostName+"')";
          //      QMessageBox::about(0,tr("create dbstring"),inserter);
          //      return ;
                query.exec(inserter);
                if (!query.isActive())
                {
                    QMessageBox::about(0,tr("Failed"),tr("Add friend in db failed"));
                    database::Close();
                    return ;
                }
                if (query.size() == 0)
                {
                    QMessageBox::about(0,tr("Failed"),tr("Add friend in db failed"));
                    database::Close();
                    return ;
                }
                QMessageBox::about(0,tr("Success"),"Success to add friend.");
                database::Close();
//                QTableWidgetItem *isfriend = new QTableWidgetItem(flagyes);
//                ui->tableWidget_2->setItem(demo.row(),2,isfriend);
//                ui->tableWidget_2->item(demo.row(),2)->text() = "yes";
                QString flagyes = "Yes";

                QTableWidgetItem *friends = new QTableWidgetItem(flagyes);
                friends->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_2->setItem(demo.row(),2,friends);
                ui->tableWidget_2->item(demo.row(),2)->setForeground(Qt::red);
                return ;
            }
            break;
        }
        case DeleteFriend:{
            in  >>localHostName >>ipAddress >> secretAddress;
//            QMessageBox::about(0,"0","test");
            QString dbtablename = ui->usernamelabel->text();
            QString friname = ui->tableWidget_2->item(demo.row(),0)->text();

            if (secretAddress != getIP()){

                if (!database::Open())
                {
                    QMessageBox::about(0,tr("Fail"),tr("Failed to connect database."));
                    database::Close();
                    return ;
                }
//                QMessageBox::about(0,"0","test");
                QSqlQuery query;
                QString inserter = "select * from "+dbtablename+"friend where friendname='"+friname+"'";
                query.exec(inserter);
//                QMessageBox::about(0,tr("query test"),inserter);
//                return ;
                std::cout << query.size() << endl;
//                return ;
                if (!query.isActive())
                {
                    QMessageBox::about(0,tr("Failed"),tr("He/She is not your friend."));
                    database::Close();
                    return ;
                }
                if (query.size() == 0)
                {
                    QMessageBox::about(0,tr("Warring!!!"),tr("He/She is not your friend."));
                    database::Close();
                    return ;
                }

                inserter = "delete from "+dbtablename+"friend where friendname='"+friname+"'";
//                QMessageBox::about(0,tr("delete dbstring"),inserter);
//                return ;
                query.exec(inserter);
                std::cout << query.size() << endl;
                if (!query.isActive())
                {
                    QMessageBox::about(0,tr("Failed"),tr("Delete friend in db failed"));
                    database::Close();
                    return ;
                }
                if (query.size() == 0)
                {
                    QMessageBox::about(0,tr("Warring!!!"),tr("Delete friend in db failed"));
                    database::Close();
                    return ;
                }
                QMessageBox::about(0,tr("Success"),"Success to delete friend.");
                database::Close();
                QString flagno = "";
                QTableWidgetItem *friends = new QTableWidgetItem(flagno);
                friends->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_2->setItem(demo.row(),2,friends);
                ui->tableWidget_2->item(demo.row(),2)->setForeground(Qt::red);
                return ;
            }
            break;
        }
        }
    }
}



void Widgt::hasPendingFile(QString localHostName, QString serverAddress,
                            QString clientAddress,QString fileName)
{
    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,tr("Receive file"),
                                           tr("From %1(%2)'s file：%3,receive？")
                                           .arg(localHostName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            QString name = QFileDialog::getSaveFileName(0,tr("save file"),fileName);
            if(!name.isEmpty())
            {
                filereceive *receiver = new filereceive(this);
                receiver->setFileName(name);
                receiver->setHostAddress(QHostAddress(serverAddress));
                receiver->move(500,200);
                receiver->show();
            }

        }
        else{
            sendMessage(Refuse,serverAddress);
        }
    }
}



void Widgt::on_tableWidget_2_doubleClicked(QModelIndex index)
{
    demo = index;
    if (m_menu == NULL)
    {
        creatMenu();
    }
    m_menu->exec(QCursor::pos());
}
void Widgt::sendMessageToFriend(){
/*    int rowcount;
//    rowcount = ui->tableWidget->rowCount();
    QList<QTableWidgetItem*>items=ui->tableWidget->selectedItems();
    int count=items.count();
    for(int i=0;i<count;i++)
        {
           rowcount = ui->tableWidget->row(items.at(i));
           //QTableWidgetItem *item = items.at(i);
           //QStringname=item->text();
        }
        */
    QString secretAddress = ui->tableWidget_2->item(demo.row(),1)->text();
//    QMessageBox::about(0,tr("test"),secretAddress);
//    return ;
//    QString secretAddress = ui->tableWidget->item(index.row(),1)->text();//对方ip
    if(secretAddress == getIP())
    {
        QMessageBox::information(this,tr("Warring"),tr("You are trying to chat with yourself."));
        return;
    }
    if(list.contains(secretAddress))
    {
        list[secretAddress]->raise();
        list[secretAddress]->activateWindow();
        list[secretAddress]->show();

        return;
    }
    sendMessage(AskStartChat,secretAddress);
}


void Widgt::on_btnAll_clicked()
{
    if(list.contains("NULL"))
    {
        list["NULL"]->raise();
        list["NULL"]->activateWindow();
        list["NULL"]->show();

    }else {
        ChatWidgit *chatView = new ChatWidgit();
        list.insert("NULL",chatView);
        connect(chatView,SIGNAL(closeChat(QString)),this,SLOT(closeFromChat(QString)));
        connect(this,SIGNAL(sendMessagesZ(QString,QString,QString)),chatView,SLOT(setMessage(QString,QString,QString)));
        connect(chatView,SIGNAL(sendMessagesFromChat(QString,QString)),this,SLOT(sendMessagesToMain(QString,QString)));

        chatView->setSecAddr("NULL",Name);
        chatView->show();
    }
}


void Widgt::sendMessage(MessageType type, QString serverAddress,QString message)
{
    if(Name == "")
        return;

    QByteArray data;
    QHostAddress addr;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = Name;
    QString address = getIP();
    out << type<< localHostName;
    switch(type)
    {
    case ParticipantLeft:
        {
            break;
        }
    case NewParticipant:
        {
            out << address;
            break;
        }
    case RefuseChat:
        {
            out<<serverAddress;
            break;
        }
    case StartChat:
        {
            out<<address<<serverAddress;
            break;
        }
    case AskStartChat:
        {
            out<<address<<serverAddress;
            break;
        }
    case Message :
        {
            out<<address<<serverAddress<<message;
            break;
        }
    case FileName:
        {
            out << address << serverAddress << message;
            break;
        }
    case Refuse:
        {
            out << address <<serverAddress;
            break;
        }
    case AskAddFriend:
    {
        out << address << serverAddress;
        break;
    }
    case RefuseFriend:{
        out << address << serverAddress;
        break;
    }
    case BeFrineds:{
        out << address << serverAddress;
    }
    case DeleteFriend:{
        out << address << serverAddress;
    }
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
}


void Widgt::sentFileName(QString fileName,QString Addr)
{
    sendMessage(FileName,Addr,fileName);
}



void Widgt::closeEvent(QCloseEvent *)
{
    QMap<QString,ChatWidgit *>::Iterator it;
    while(list.size() > 0)
    {
        it=list.begin();
        list[it.key()]->close();
    }
    sendMessage(ParticipantLeft);
}

void Widgt::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widgt::newParticipant(QString localHostName,QString ipAddress)
{
//    QString demovalue2;
    qDebug() << "rowcount" << ui->tableWidget_2->rowCount();
//    return ;
    /*
    for (int i = 0; i < ui->tableWidget_2->rowCount() ; i++)
    {
        qDebug() << "test";
//        return ;
        demovalue2 = ui->tableWidget_2->item(i,0)->text();
        if (demovalue2 == localHostName)
        {
            QMessageBox::about(0,"Warring!!!","You have login.");
            this->hide();
            return ;
        }
    }
    */
    bool bb = ui->tableWidget_2->findItems(localHostName,Qt::MatchExactly).isEmpty();
    if(bb)
    {
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
        host->setTextAlignment(Qt::AlignCenter);
        ip->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_2->insertRow(0);
        ui->tableWidget_2->setItem(0,0,host);
        ui->tableWidget_2->setItem(0,1,ip);
        ui->tableWidget_2->resizeColumnToContents(1);
        ui->lbOnline->setText(tr("在线人数：%1").arg(ui->tableWidget_2->rowCount()));
        synclist();
        sendMessage(NewParticipant);
    }
}

void Widgt::participantLeft(QString localHostName,QString time)
{
    int rowNum = ui->tableWidget_2->findItems(localHostName,Qt::MatchExactly).first()->row();
    ui->tableWidget_2->removeRow(rowNum);
    QSqlQuery query;
    QString inserter = "delete from onlineperson where username='"+localHostName+"'";
    if(!database::Open())
    {
        QMessageBox::about(0,tr("Fail"),tr("Failed to connect database."));
        database::Close();
        return ;
    }

    query.exec(inserter);

    if (!query.isActive())
    {
        QMessageBox::about(0,tr("Warring"),tr("!!!"));
        database::Close();
        return ;

    }
    QMessageBox::about(0,tr("Notice!"),"user "+localHostName+" have leave.");
    qDebug() << "Localhostname" << localHostName;
    qDebug() << "time" << time;
    ui->lbOnline->setText(tr("在线人数：%1").arg(ui->tableWidget_2->rowCount()));
}

void Widgt::hasFileToSend(QString fileName, QString SecretAddress)
{
    this->Sender->initSender();
    this->Sender->SenderStart(fileName,SecretAddress);
    this->Sender->move(500,200);
    this->Sender->show();
}

void Widgt::sendMessagesToMain(QString message,QString secretAddr)
{
    sendMessage(Message,secretAddr,message);
}


void Widgt::closeFromChat(QString addr)
{
    list.remove(addr);
}


Widgt::~Widgt()
{
    delete ui;
}

QString Widgt::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    //qDebug() << list;
    foreach (QHostAddress address, list)
    {
       if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
           if(address.toString()!="127.0.0.1")
                return address.toString();
        }
    }
    return 0;
}



void Widgt::recvdata(QString data)
{
    ui->usernamelabel->setText(data);
}


/*
void Widgt::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        onClickRightButton();
        return;
    }
    //QPushButton::mousePressEvent(event);
}
*/
void Widgt::creatMenu()
{
    m_menu = new QMenu(this);
    QAction *sendMessage = new QAction(tr("发送即时消息"), m_menu);

    QAction *addfri = new QAction(tr("添加好友"),m_menu);

    QAction *showInfo = new QAction(tr("查看资料"), m_menu);

    QAction *removeFriend = new QAction(tr("删除好友"), m_menu);

    QAction *shuaxin = new QAction(tr("刷新"),m_menu);



    connect(sendMessage, SIGNAL(triggered()),
        this, SLOT(sendMessageToFriend()));

    connect(addfri,SIGNAL(triggered()),
            this,SLOT(addfri()));

    connect(showInfo, SIGNAL(triggered()),
        this, SLOT(userinformation()));

    connect(removeFriend, SIGNAL(triggered()),
        this, SLOT(deletefri()));

    connect(shuaxin,SIGNAL(triggered()),this,SLOT(synclist()));

    m_menu->addAction(sendMessage);
    m_menu->addAction(addfri);
    m_menu->addAction(showInfo);

    m_menu->addSeparator();
    m_menu->addAction(removeFriend);
    m_menu->addSeparator();
    m_menu->addAction(shuaxin);
}

void Widgt::addfri()
{
//    QString ipaddress = getIP();
//    QString localHostName = ui->tableWidget_2->item(demo.row(),0)->text();
    QString secretAddress = ui->tableWidget_2->item(demo.row(),1)->text();
//    QMessageBox::about(0,tr("test"),secretAddress);
//    return ;
//    QString secretAddress = ui->tableWidget->item(index.row(),1)->text();//对方ip
    if(secretAddress != getIP())
    {
        if(list.contains(secretAddress))
        {
            list[secretAddress]->raise();
            list[secretAddress]->activateWindow();
            list[secretAddress]->show();

            return;
        }
    }else{
        QMessageBox::about(0,tr("Warring!!!"),tr("You are trying to add yourself as friend."));
        return ;
    }
    sendMessage(AskAddFriend,secretAddress);

}

void Widgt::userinformation()
{
//    QMessageBox::about(0,tr("Test"),"userinfo");
    QString realname,sex,phone,registime;
    QString localHostName = ui->tableWidget_2->item(demo.row(),0)->text();
//    QMessageBox::about(0,tr("Test"),localHostName);
//    return ;
    if(!database::Open())
    {
        QMessageBox::about(0,tr("Fail"),tr("Failed to connect database."));
        database::Close();
        return ;
    }
    QSqlQuery query;
    QString inserter = "select realname,sex,phone,registime from ChatUser where username='"+localHostName+"'";
    query.exec(inserter);
    if(!query.isActive())
    {
        QMessageBox::about(0,tr("Error"),tr("Failed!"));
        database::Close();
        return ;
    }
    if(query.size() == 0)
    {
        QMessageBox::about(0,tr("Error"),tr("Failed!"));
        database::Close();
        return ;
    }
    while(query.next()){
        userinfo *usrinfo = new userinfo;
        connect(this,SIGNAL(senduserinfo(QString,QString,QString,QString,QString)),\
                usrinfo,SLOT(recvuserinfo(QString,QString,QString,QString,QString)));
        realname = query.value(0).toString();
        sex = query.value(1).toString();
        phone = query.value(2).toString();
        registime = query.value(3).toString();
        emit senduserinfo(localHostName,realname,sex,phone,registime);
        usrinfo->show();
    }
    database::Close();
    return ;
}
void Widgt::deletefri()
{
    QString secretAddress = ui->tableWidget_2->item(demo.row(),1)->text();
//    QMessageBox::about(0,tr("test"),secretAddress);
//    return ;
//    QString secretAddress = ui->tableWidget->item(index.row(),1)->text();//对方ip
    if(secretAddress != getIP())
    {
        if(list.contains(secretAddress))
        {
            list[secretAddress]->raise();
            list[secretAddress]->activateWindow();
            list[secretAddress]->show();

            return;
        }
    }
    else{
        QMessageBox::about(0,tr("Warring!!!"),tr("YOu are trying to delete yourself."));
        return ;
    }
    sendMessage(DeleteFriend,secretAddress);
//    QMessageBox::about(0,tr("Test"),"deletefri");
//    return ;
}

void Widgt::synclist()
{
    //QModelIndex indexdemo;
    QString demovalue,demovalue2;
    //QModelIndex i = 0;
    if (!database::Open())
    {
        QMessageBox::about(0,tr("Error"),tr("Failed to connect database!"));
        database::Close();
        return ;
    }
    QSqlQuery query;
    QString usernamedemo;
    usernamedemo = ui->usernamelabel->text();
    QString inserter = "select * from "+usernamedemo+"friend";

    query.exec(inserter);

    if (!query.isActive())
    {
        QMessageBox::about(0,tr("Error"),tr("Faild").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    if (query.size() == 0)
    {
        QMessageBox::about(0,tr("Warring"),tr("Nothing!").arg(query.lastError().text()));
        database::Close();
        return ;
    }


    while (query.next())
    {
        demovalue = query.value(0).toString();
//        qDebug() << tttt;
        for (int i = 0; i < ui->tableWidget_2->rowCount() ; i++)
        {
            demovalue2 = ui->tableWidget_2->item(i,0)->text();
            if (demovalue == demovalue2)
            {
                QString flagyes = "Yes";
                QTableWidgetItem *friends = new QTableWidgetItem(flagyes);
                friends->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_2->setItem(i,2,friends);
                ui->tableWidget_2->item(i,2)->setForeground(Qt::red);
            }else{
                break;
            }
        }

    }
    database::Close();
    return ;

}
void Widgt::recvkeydata(QString data)
{
    keycontent = data;
}
