#include "addfriend.h"
#include "ui_addfriend.h"
#include "database.h"
#include <QMessageBox>

addfriend::addfriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);
}

addfriend::~addfriend()
{
    delete ui;
}

void addfriend::on_pushButton_clicked()
{
    if(!database::Open())
    {
        QMessageBox::about(0,tr("Error"),tr("Failed to connect database."));
        database::Close();
        return ;
    }
    QString searchname;
    searchname = ui->lineEdit->text();
    QMessageBox::about(0,"TEST","This is just a test.");
}
