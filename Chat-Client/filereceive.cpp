#include "filereceive.h"
#include "ui_filereceive.h"
#include <QFileDialog>
#include <QMessageBox>


filereceive::filereceive(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::filereceive)
{
    ui->setupUi(this);

    TotalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    FileReceiver = new QTcpSocket(this);
    tcpPort = 6666;
    connect(FileReceiver,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(FileReceiver,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(displayError(QAbstractSocket::SocketError)));

}

filereceive::~filereceive()
{
    delete ui;
}

void filereceive::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void filereceive::setHostAddress(QHostAddress address)
{
    hostAddress = address;
    newConnect();
}

void filereceive::newConnect()
{
    blockSize = 0;
    FileReceiver->abort();
    FileReceiver->connectToHost(hostAddress,tcpPort);
    time.start();
}


void filereceive::readMessage()
{
    QDataStream in(FileReceiver);
    in.setVersion(QDataStream::Qt_4_6);

    float useTime = time.elapsed();

    qDebug() << sizeof(qint64)*2 ;

    if(bytesReceived <= sizeof(qint64)*2){
        if((FileReceiver->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0)){
            in>>TotalBytes>>fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if((FileReceiver->bytesAvailable() >= fileNameSize) && (fileNameSize != 0)){
            in>>fileName;
            bytesReceived +=fileNameSize;

            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }
        else
            return;
    }
    if(bytesReceived < TotalBytes){
        bytesReceived += FileReceiver->bytesAvailable();
        inBlock = FileReceiver->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesReceived);
    qDebug()<<bytesReceived<<"received"<<TotalBytes;

    double speed = bytesReceived / useTime;
    ui->FileReceiverStatusLabel->setText(tr("已接收 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
                                         .arg(bytesReceived / (1024*1024))//已接收
                                         .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                         .arg(TotalBytes / (1024 * 1024))//总大小
                                         .arg(useTime/1000,0,'f',0)//用时
                                         .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间

    if(bytesReceived == TotalBytes)
    {
        FileReceiver->close();
        ui->FileReceiverStatusLabel->setText(tr("接收文件 %1 完毕").arg(fileName));
        localFile->close();
    }
}
void filereceive::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
        case QAbstractSocket::RemoteHostClosedError : break;
        default : qDebug() << FileReceiver->errorString();
    }
}

void filereceive::on_btnCancel_clicked()
{
    FileReceiver->abort();
}

void filereceive::on_btnClose_clicked()
{
    FileReceiver->abort();
    this->close();
}
