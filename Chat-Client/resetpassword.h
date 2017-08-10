#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class resetpassword;
}

class resetpassword : public QDialog
{
    Q_OBJECT

public:
    explicit resetpassword(QWidget *parent = 0);
    ~resetpassword();
    void setvalue(QString data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::resetpassword *ui;

signals:
    void senddata(QString);
};

#endif // RESETPASSWORD_H
