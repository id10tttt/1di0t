#ifndef FILESEND_H
#define FILESEND_H

#include <QDialog>
#include <QTcpServer>
#include <QFile>
#include <QTime>

namespace Ui {
    class filesend;
}

class filesend : public QDialog
{
    Q_OBJECT

public:
    explicit filesend(QWidget *parent = 0);
    ~filesend();
    void refused();
    void initSender();
    void SenderStart(QString,QString);
protected:
    void changeEvent(QEvent *e);
private:
    Ui::filesend *ui;
    qint16 tcpPort;
    QTcpServer *fileSender;
    QString fileName;
    QString theFileName;
    QFile *localFile;

    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QByteArray outBlock;
    QTcpSocket*clientConnection;
    QTime time;

private slots:
    void on_btnQuit_clicked();
    void sendMessage();
    void updateClientProgress(qint64 numBytes);
signals:
    void sendFileName(QString fileName,QString addr);
};



#endif // FILESEND_H
