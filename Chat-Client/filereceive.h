#ifndef FILERECEIVE_H
#define FILERECEIVE_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QTime>
namespace Ui {
    class filereceive;
}

class filereceive : public QDialog
{
    Q_OBJECT

public:
    explicit filereceive(QWidget *parent = 0);
    ~filereceive();
    void setHostAddress(QHostAddress address);
    void setFileName(QString fileName){localFile = new QFile(fileName);}
    void newConnect();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::filereceive *ui;
    QTcpSocket *FileReceiver;
    quint16 blockSize;
    QHostAddress hostAddress;
    qint16 tcpPort;

    qint64 TotalBytes;
    qint64 bytesReceived;
    qint64 bytesToReceive;
    qint64 fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;

    QTime time;

private slots:
    void on_btnClose_clicked();
    void on_btnCancel_clicked();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
};


#endif // FILERECEIVE_H
