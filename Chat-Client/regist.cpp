#include "regist.h"
#include "define.h"
#include "ui_regist.h"
#include "database.h"
#include <string.h>
#include <QMessageBox>
#include <QtSql>
#include <qsqlquery.h>
#include <iostream>

using namespace std;

regist::regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_2_clicked()
{
    this->hide();
}

void regist::on_pushButton_clicked()
{
    time_t  ticks;
    char    timebuff[40];

    ticks = time(NULL);
    snprintf(timebuff,sizeof(timebuff),"%.24s",ctime(&ticks));
    QString username, realname, password, repetpassword, sex, phone, question, answer;
    QString md5pwd,md5answer;

    if(!database::Open()){
        QMessageBox::about(0,tr("Error!"),tr("Fail to open the database.\n%1"));
        return ;
    }

    if(!ui->username->text().isEmpty())
        username = ui->username->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Username cat't empty."));
        database::Close();
        return ;
    }
    if(!ui->realname->text().isEmpty())
        realname = ui->realname->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Realname can't empty."));
        database::Close();
        return ;
    }
    if(!ui->password->text().isEmpty())
        password = ui->password->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Password can't empty."));
        database::Close();
        return ;
    }
    if (ui->password->text().length() <= 6)
    {
        QMessageBox::about(0,tr("Notice"),tr("You password is too short!!!"));
        database::Close();
        return ;
    }
    if(!ui->repetpassword->text().isEmpty())
        repetpassword = ui->repetpassword->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Repetpassword can't empty."));
        database::Close();
        return ;
    }
    if(password.compare(repetpassword) != 0){
        QMessageBox::about(0,tr("Notice"),tr("Password not equal to repetpassword."));
        database::Close();
        return ;
    }
    if(!ui->question->text().isEmpty())
        question = ui->question->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Question can't empty."));
        database::Close();
        return ;
    }
    if(!ui->answer->text().isEmpty())
        answer = ui->answer->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Answer can't empty."));
        database::Close();
        return ;
    }
    if(!ui->sex->text().isEmpty())
        sex = ui->sex->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Sex can't empty."));
        database::Close();
        return ;
    }
    if(!ui->phone->text().isEmpty())
        phone = ui->phone->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Phone can't empty."));
        database::Close();
        return ;
    }
    QSqlQuery query,query1;
    int id;
    query.exec("select max(ID) from ChatUser");
    if(!query.next())
        return;
    id = query.value(0).toInt()+1;

    QByteArray bb1,bb2;
    bb1 = QCryptographicHash::hash ( password.toAscii(), QCryptographicHash::Md5 );
    md5pwd = bb1.toHex();
    //        md5pwd = MDString(MyOwnQStringToChar(password));
    bb2 = QCryptographicHash::hash(answer.toAscii(),QCryptographicHash::Md5);
    //        md5answer = MDString(MyOwnQStringToChar(answer));
    md5answer = bb2.toHex();
    QString insertstr1 = "select * from ChatUser where username='"+username+"'";
    query1.exec(insertstr1);

    if(!query1.isActive()){
        QMessageBox::about(0,tr("Error."),tr("Failed."));
        database::Close();
        return ;
    }

/*
    std::cout << query1.size() << endl;
    QString s = QString::number(query.size(),10);
    QMessageBox::about(0,tr("TEST"),s);
    return ;
*/

    if(query1.size() != 0){
        QMessageBox::about(0,tr("Error!!!"),tr("This user is exist."));
        database::Close();
        return ;
    }
    QString insertstr="insert into ChatUser(ID,username,realname,password, sex, phone, question, answer,registime) values('"+QString::number(id)+"','"+username+"','"+realname+"','"+md5pwd+"',"
                                                                                                                                                                                            "'"+sex+"','"+phone+"','"+question+"','"+md5answer+"','"+timebuff+"')";

    //        QMessageBox::about(0,"Hello",insertstr);
    //        exit(0);

    query.exec(insertstr);

    if(!query.isActive()){
        QMessageBox::about(0,tr("Fail"),tr("Regist Fail.\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }

    if(query.size() == 0)
    {
        QMessageBox::about(0,tr("Fail"),tr("Regist failed\n%1").arg(query.lastError().text()));
        database::Close();
        return;
    }
    QMessageBox::about(0,tr("Success"),tr("Regist Success."));

    database::Close();
    this->close();
}
