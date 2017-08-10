#include "userinfo.h"
#include "ui_userinfo.h"

userinfo::userinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfo)
{
    ui->setupUi(this);
}

userinfo::~userinfo()
{
    delete ui;
}

void userinfo::recvuserinfo(QString username, QString realname, QString sex, QString phone, QString registime)
{
    ui->username->setText(username);
    ui->realname->setText(realname);
    ui->sex->setText(sex);
    ui->phone->setText(phone);
    ui->registime->setText(registime);
}
