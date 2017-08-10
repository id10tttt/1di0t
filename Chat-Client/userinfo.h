#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

namespace Ui {
class userinfo;
}

class userinfo : public QWidget
{
    Q_OBJECT

public:
    explicit userinfo(QWidget *parent = 0);
    ~userinfo();

private:
    Ui::userinfo *ui;
private slots:
        void recvuserinfo(QString username,QString realname,QString sex,QString phone,QString registime);
};

#endif // USERINFO_H
