#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_about.h"
#include "about.h"
#include "ui_regist.h"
#include "regist.h"
#include "widgt.h"
#include "resetpassword.h"
#include "ui_resetpassword.h"
#include "ui_widgt.h"
#include <QtSql>
#include <qsqlquery.h>
#include "database.h"
#include "md5.h"
#include "define.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionAbout_triggered()
{
//    this->hide();
    about().show();
    about().exec();
//    this->show();
}

void MainWindow::on_pushButton_clicked()
{
    regist().show();
    regist().exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString username,password,md5pwd;

    if(!ui->lineEdit->text().isEmpty()){
        username = ui->lineEdit->text();
    }else{
        QMessageBox::about(0,tr("Notice"),tr("Username can't empty"));
    }

    if(!ui->lineEdit_2->text().isEmpty())
        password = ui->lineEdit_2->text();
    else{
        QMessageBox::about(0,tr("Notice"),tr("Password can't empty."));
        return ;
    }
    QByteArray bb;
    bb = QCryptographicHash::hash ( password.toAscii(), QCryptographicHash::Md5 );
    md5pwd = bb.toHex();
//    md5pwd = MDString(MyOwnQStringToChar(password));
//    QMessageBox::about(0,md5pwd,md5);
//    return ;
    QString insertstr="select * from ChatUser where username='"+username+"' and password='"+md5pwd+"'";

//    QMessageBox::about(0,"Hello",insertstr);
//    return ;

    if(!database::Open()){
        QMessageBox::about(0,tr("Error"),"Failed to open database.");
        return ;
    }
    QSqlQuery query;

    query.exec(insertstr);

    if(!query.isActive()){
        QMessageBox::about(0,tr("Fail"),tr("Login Fail..You have login in.\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    if(query.size() == 0)
    {
        QMessageBox::about(0,tr("Error"),tr("Login failed.Wrong username or password.\n%1").arg(query.lastError().text()));
        database::Close();
        return;
    }
    this->hide();
    Widgt *dp = new Widgt;
    connect(this,SIGNAL(senddata(QString)),dp,SLOT(recvdata(QString)));
    emit senddata(ui->lineEdit->text());
    dp->SetName(ui->lineEdit->text());
    insertstr = "select * from onlineperson where username='"+username+"'";
    query.exec(insertstr);
    if (!query.isActive())
    {
        QMessageBox::about(0,"Error!","User "+username+" have been login!");
        database::Close();
        return ;
    }
    qDebug() << "query.size()" << query.size();
//    return ;

    if(query.size() != 0)
    {
        QMessageBox::about(0,tr("Warring test"),tr("Login failed..You have login in.\n%1").arg(query.lastError().text()));
        database::Close();
        return;
    }
    QString inserter = "insert into onlineperson(username) values('"+username+"')";
    qDebug() << "inserter" << inserter;
    if (!database::Open())
    {
        QMessageBox::about(0,tr("Fail"),tr("Failed to connect database."));
        database::Close();
        return ;
    }

    query.exec(inserter);
    if (!query.isActive())
    {
        QMessageBox::about(0,tr("Error test"),"user "+username+" has been login");
        database::Close();
        return ;
    }

    dp->show();
    database::Close();

}

void MainWindow::on_pushButton_2_clicked()
{
    resetpassword().show();
    resetpassword().exec();
}
