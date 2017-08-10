#ifndef CHANGEPWD_H
#define CHANGEPWD_H

#include <QWidget>

namespace Ui {
class changepwd;
}

class changepwd : public QWidget
{
    Q_OBJECT

public:
    explicit changepwd(QWidget *parent = 0);
    ~changepwd();
private slots:
    void recedata(QString data);
    void on_pushButton_clicked();

private:
    Ui::changepwd *ui;
};

#endif // CHANGEPWD_H
