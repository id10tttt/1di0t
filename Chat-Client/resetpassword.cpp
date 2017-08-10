#include "resetpassword.h"
#include "question.h"
#include "ui_question.h"
#include "ui_resetpassword.h"
#include "define.h"
#include "database.h"

QString globaldata;


resetpassword::resetpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetpassword)
{
    ui->setupUi(this);
//    question *q = new question;
//    connect(this,SIGNAL(senddata(QString)),q,SLOT(receivedata(QString)));
//    q->show();
}

resetpassword::~resetpassword()
{
    delete ui;
}

void resetpassword::on_pushButton_clicked()
{
    question *q = new question;
    connect(this,SIGNAL(senddata(QString)),q,SLOT(receivedata(QString)));
    //emit senddata(ui->lineEdit->text());
    QString username;
    if(!ui->lineEdit->text().isEmpty())
    {
        username = ui->lineEdit->text();
    }else{
        QMessageBox::about(0,tr("Notice"),tr("Username cat't empty."));
        return ;
    }
    if(!database::Open()){
        QMessageBox::about(0,tr("Error!"),tr("Fail to open the database.\n%1"));
        database::Close();
        return ;
    }
    QSqlQuery query;
    QString insertstr = "select * from ChatUser where username='"+username+"'";
//    QMessageBox::about(0,"1",insertstr);

    query.exec(insertstr);

    if(!query.isActive()){
        QMessageBox::about(0,tr("Fail"),tr("No such user.\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    if(query.size() == 0)
    {
        QMessageBox::about(0,tr("Result"),tr("No such user.\n%1").arg(query.lastError().text()));
        database::Close();
        return;
    }else{
        emit senddata(ui->lineEdit->text());
        q->show();
        this->hide();
    }

//    return ;
    /*else{*/

//        emit senddata(ui->lineEdit->text());
//        question().show();
//        this->hide();
//    }
    database::Close();
}

void resetpassword::setvalue(QString data)
{
    ui->lineEdit->setText(data);
}
