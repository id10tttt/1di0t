#include "changepwd.h"
#include <QMessageBox>
#include <qsqlquery.h>
#include "ui_changepwd.h"
#include "database.h"
#include <QtSql>
#include <string.h>
#include <define.h>

changepwd::changepwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changepwd)
{
    ui->setupUi(this);
}

changepwd::~changepwd()
{
    delete ui;
}
void changepwd::recedata(QString data)
{
    ui->label->setText(data);
}

void changepwd::on_pushButton_clicked()
{
    QString pwd1,pwd2,pwd,name;
    QByteArray bb;
    pwd1 = ui->lineEdit->text();
    pwd2 = ui->lineEdit_2->text();
    name = ui->label->text();
    if (pwd1 == pwd2)
    {
        bb = QCryptographicHash::hash ( pwd1.toAscii(), QCryptographicHash::Md5 );
        pwd = bb.toHex();

        if(!database::Open()){
            QMessageBox::about(0,tr("Error!"),tr("Fail to open the database.\n%1"));
            return ;
        }

        QSqlQuery query;
        QString inserter = "update ChatUser set password='"+pwd+"' where username='"+name+"'";
        query.exec(inserter);
        if(!query.isActive())
        {
            QMessageBox::about(0,tr("Error"),tr("Change password failed\n%1").arg(query.lastError().text()));
            database::Close();
            return ;
        }
        if(query.size() == 0)
        {
            QMessageBox::about(0,tr("Error"),tr("Change password failed\n%1").arg(query.lastError().text()));
            database::Close();
            return ;
        }else{
            QMessageBox::about(0,tr("Success!"),tr("Change password successful."));
            database::Close();
            this->close();
            return ;
        }

    }else{
        QMessageBox::about(0,tr("Error"),tr("The password is not equal."));
        return ;
    }
}
