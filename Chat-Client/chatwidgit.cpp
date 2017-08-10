#include "chatwidgit.h"
#include "ui_chatwidgit.h"
#include "database.h"
#include <qsqlquery.h>
#include <QtSql>
#include "aestools.h"
#include "Rijndael.h"


char secretmessage[10000];
char realmessage[10000];
char *datamessage;
QString secretkeycontent;
QByteArray ccc;
//UCHAR    *dataofsecretkeycontent;

//将html格式的qstring 转换
QString simplifyRichText( QString f_richText )
{
    QRegExp rxBody("<body[^>]*>(.*)</body>");
    if(rxBody.indexIn(f_richText))
    {
        f_richText = rxBody.cap(1); // throw away anything not in the body, and the body tags as well
        f_richText.replace(QRegExp("^\\s+"),""); // throw away any leading whitespace (be it new lines or spaces)
    }
    QRegExp rxBody1("<span[^>]*>(.*)</span>");
    if(f_richText.indexOf(rxBody1) != -1){
        if(rxBody1.indexIn(f_richText))
        {
            f_richText = rxBody1.cap(1); // throw away anything not in the body, and the body tags as well
            f_richText.replace(QRegExp("^\\s+"),""); // throw away any leading whitespace (be it new lines or spaces)
        }
    }
    f_richText.replace(QRegExp("<p style=\"[^\"]*\">"),"<p>"); // throw away paragraph styles


    if(f_richText == "<p></p>") // thats what we get for an empty QTextEdit
        return QString();
    f_richText.replace("<p>","");
    f_richText.replace("</p>","");

    return f_richText;
}




ChatWidgit::ChatWidgit(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ChatWidgit)
{
    ui->setupUi(this);
    ui->tbHistory->hide();
    ui->teEdit->setFocusPolicy(Qt::StrongFocus);
    ui->teEdit->setFocus();
    ui->teEdit->installEventFilter(this);


}

ChatWidgit::~ChatWidgit()
{
    delete ui;
}



void ChatWidgit::setMessage(QString address, QString first, QString second)
{
    if(address == secretAddress ){
        ui->tbShow->setTextColor(Qt::blue);
        ui->tbShow->setCurrentFont(QFont("Times New Roman",12));
        ui->tbShow->append(first);

        qDebug() << "miwen jieshou:" << second;

        secretkeycontent = ui->secretKey->text();
        QString *keytext = &secretkeycontent;
        AESTools tools(keytext);
        const QString *miwen = &second;
        qDebug() << "miwen receive:" << miwen;
        QString *mingwen = tools.Decrypt(miwen);
        qDebug() << "mingwen decrypt:" << *mingwen;
        QString mingwendata = *mingwen;
/*
        qDebug() << "secretMessage: " << second;
        ccc = second.toLocal8Bit();
        datamessage = strdup(ccc.data());
//        const QByteArray abcd = second.toLocal8Bit();
//        const char *dataofmessage = abcd.data();
//        DWORD sizeofmessage = strlen(dataofmessage);

        dataofsecretkeycontent = (UCHAR *)qstrdup(secretkeycontent.toAscii().constData());
//        TAesClass *aes = new TAesClass;
        printf("%s",&dataofsecretkeycontent);
        qDebug() << "dataofsecretkeycontent:" << dataofsecretkeycontent;
        aes->InitializePrivateKey(16,dataofsecretkeycontent);
        aes->OnAesUncrypt((LPVOID)datamessage,(DWORD)strlen(datamessage),(LPVOID)realmessage);
//        QString second2 = QString(QLatin1String(realmessage));
//        qDebug() << "secretkeycontent:" << secretkeycontent;
        //qDebug() << "message:" << second2;
        qDebug() << "realmessage: " << realmessage;
        ui->tbShow->append(QString(QLatin1String(realmessage)));
*/
        ui->tbShow->append(mingwendata);

        //        QMessageBox::information(this,tr("a"),tr("%1\n%2").arg(first).arg(second));

        if(!saveFile.open(QFile::WriteOnly | QFile::Text | QFile::Append))

        {
            QMessageBox::warning(this,tr("Save files."),
                                 tr("Can't save file :\n %1").arg(saveFile.errorString()));
            return;
        }
        QTextStream out(&saveFile);
        out << first <<endl << simplifyRichText(mingwendata) <<endl;

        saveFile.close();
    }
}


QString ChatWidgit::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
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


QString ChatWidgit::getSecAddr()
{
    return this->secretAddress;
}


void ChatWidgit::setSecAddr(QString addr,QString realname)
{
    this->secretAddress = addr;
    if(secretAddress == "NULL"){
        ui->lbConn->setText(tr("His/Her ip: All"));
        ui->secretKey->setText("Input yourself.");
        ui->textSave->hide();
//        ui->secretKey->hide();
//        ui->label->hide();
    }
    else
        ui->lbConn->setText(tr("His/Her ip：%1").arg(secretAddress));
    QDir dir;
    dir.mkpath("history");

    saveFile.setFileName(tr("history\\%1%2.chat").arg(addr).arg(realname));
    this->setWindowTitle(tr("Chatting--%1").arg(realname));
}


void ChatWidgit::on_btnSend_clicked()
{
    if(ui->teEdit->toPlainText() == "")
    {
        QMessageBox::warning(0,tr("Warring!"),tr("You are forbidden to send empty message."),QMessageBox::Ok);
        return;
    }

    if(ui->secretKey->text().isEmpty()){
        QMessageBox::about(0,tr("Warring"),tr("Key can't empty!"));
        return ;
    }
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString message = ui->teEdit->toHtml();

    secretkeycontent = ui->secretKey->text();
    QString *keytext = &secretkeycontent;

    AESTools tools(keytext);
    const QString *messagedata = &message;
    QString *miwen = tools.Encrypt(messagedata);

    qDebug() << "miwen:" << *miwen;
    QString test = *miwen;
    qDebug() << "test:" << test;
//    QMessageBox::about(0,tr("test"),test);
//    QString *mingwen = tools.Decrypt(miwen);
//    qDebug() << "mingwen:" << *mingwen;
//    return ;
/*
    dataofsecretkeycontent = (UCHAR *)qstrdup(secretkeycontent.toAscii().constData());


    const QByteArray abcd = message.toLocal8Bit();
    ccc = message.toLatin1();
    datamessage = strdup(ccc.data());
    const char *dataofmessage = abcd.data();
    DWORD sizeofmessage = strlen(dataofmessage);

    qDebug() << "dataofsecretkeycontent:" << dataofsecretkeycontent;
//    return ;
    printf("%s\n",&dataofsecretkeycontent);
    aes->InitializePrivateKey(16,dataofsecretkeycontent);
    aes->OnAesEncrypt((LPVOID)datamessage,sizeofmessage,(LPVOID)secretmessage);
    qDebug() << "message: " << message;
    qDebug() << "secretmessage: " << secretmessage;
//    aes->InitializePrivateKey(16,dataofsecretkeycontent);
//    aes->OnAesUncrypt((LPVOID)secretmessage,(DWORD)sizeof(secretmessage),(LPVOID)realmessage);

//    qDebug() << "realmessage: " << realmessage;
//    qDebug() << "secretkeycontent: " << secretkeycontent;
//return ;
//    QMessageBox::about(0,"test",secretAddress);
*/
    if(secretAddress != "NULL"){
        ui->tbShow->setTextColor(Qt::blue);
        ui->tbShow->setCurrentFont(QFont("Times New Roman",12));
        ui->tbShow->append(tr("[ You say ]  %1").arg(time));
        ui->tbShow->append(message);

        if(!saveFile.open(QFile::WriteOnly | QFile::Text | QFile::Append))

        {
            QMessageBox::warning(this,tr("Save files."),
                                 tr("Can't save file :\n %1").arg(saveFile.errorString()));
            return;
        }
        QTextStream out(&saveFile);
        out <<tr("[ You say ]  %1").arg(time)<<endl << simplifyRichText(message)<<endl;

        saveFile.close();
    }

    ui->teEdit->clear();
    ui->teEdit->setFocus();
//    char *p = (char*)secretmessage;
    emit sendMessagesFromChat(test,secretAddress);
//    emit sendMessagesFromChat(message,secretAddress);
}

// ctrl + enter 发送
bool ChatWidgit::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->teEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *k = static_cast<QKeyEvent *>(event);
            //if (k->key() == Qt::Key_Return)
            if (k->key() == Qt::Key_Return && (k->modifiers() & Qt::ControlModifier))
            {
                on_btnSend_clicked();
                return true;
            }
        }
    }
    return QWidget::eventFilter(target,event);
}


void ChatWidgit::closeEvent(QCloseEvent *)
{
    emit closeChat(secretAddress);
    //    this->destroyed(0);
}



void ChatWidgit::on_textBin_clicked()
{
    ui->tbShow->clear();
}


void ChatWidgit::on_textSave_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,tr("Warring!"),tr("Please choose a file."));
        return;
    }

    emit sendFile(fileName,secretAddress);
}



void ChatWidgit::on_textHistory_clicked()
{
    if(ui->tbHistory->isHidden())
    {
        if(!saveFile.open(QFile::ReadOnly))
        {
            QMessageBox::warning(this,tr("Save files."),
                                 tr("Can't save file :\n %1").arg(saveFile.errorString()));
            return ;
        }

        QTextStream t(&saveFile);

        ui->tbHistory->setText(t.readAll());
        ui->tbHistory->verticalScrollBar()->setValue(ui->tbHistory->verticalScrollBar()->maximum());
        saveFile.close();
        ui->tbHistory->show();
    }
    else{
        ui->tbHistory->hide();
    }
}

void ChatWidgit::on_btnClose_clicked()
{
    this->close();
}
