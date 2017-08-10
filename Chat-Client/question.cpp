#include "question.h"
#include "changepwd.h"
#include "ui_changepwd.h"
#include "ui_question.h"
#include "resetpassword.h"
#include "define.h"
#include "database.h"
#include "md5.h"
#include "ui_resetpassword.h"

extern QString globaldata;

question::question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);
}

question::~question()
{
    delete ui;
}

void question::on_pushButton_clicked()
{
    changepwd *cpwd = new changepwd;
    connect(this,SIGNAL(send(QString)),cpwd,SLOT(recedata(QString)));
    emit send(ui->username->text());
    QString user;
    user = ui->username->text();
    QSqlQuery query;
    QString q;
    q = ui->label_4->text();
    QString ansmd5,ans;
    //ans = MDString(MyOwnQStringToChar(ui->lineEdit->text()));
    QByteArray bb;
    ans = ui->lineEdit->text();
    bb = QCryptographicHash::hash ( ans.toAscii(), QCryptographicHash::Md5 );
    ansmd5 = bb.toHex();
    QString insertstr = "select answer from ChatUser where question='"+q+"' and username='"+user+"'";
    if(!database::Open()){
        QMessageBox::about(0,tr("Error!"),tr("Fail to open the database.\n%1"));
        return ;
    }
//    QMessageBox::about(0,"1",insertstr);
//    return ;
    query.exec(insertstr);
//    QMessageBox::about(0,"debug","TEST");
//    QMessageBox::about(0,"1",ans);
//    while(query.next()){
        //QMessageBox::about(0,"1",query.value(0).toString());
//    }
    if(!query.isActive()){
        QMessageBox::about(0,tr("Fail"),tr("The answer is wrong.\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    if(query.size() == 0)
    {
        QMessageBox::about(0,tr("Result"),tr("The answer is wrong\n%1").arg(query.lastError().text()));
        database::Close();
        return;
    }
    while(query.next())
    {
        if(ansmd5 == query.value(0).toString()){
            this->hide();
            cpwd->show();
        }
    }

    database::Close();
}
void question::receivedata(QString data)
{
    ui->username->setText(data);
}

void question::on_pushButton_2_clicked()
{
    QString user;
    user = ui->username->text();
    if(!database::Open()){
        QMessageBox::about(0,tr("Error!"),tr("Fail to open the database.\n%1"));
        return ;
    }
    QSqlQuery query;
    QString insertstr = "select question from ChatUser where username='"+user+"'";
//    QMessageBox::about(0,"1",insertstr);
//    return ;
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
    }
    while(query.next()){
        ui->label_4->setText(query.value(0).toString());
    }
    database::Close();
}
