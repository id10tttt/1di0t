#include "filesend.h"
#include "ui_filesend.h"

#include <QTcpSocket>
#include <QFileDialog>
#include <QMessageBox>


filesend::filesend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filesend)
{
    ui->setupUi(this);
    tcpPort = 6666;
    fileSender = new QTcpServer();
    connect(fileSender,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}

filesend::~filesend()
{
    delete ui;
}

void filesend::changeEvent(QEvent *e)
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


void filesend::sendMessage()
{
    clientConnection = fileSender->nextPendingConnection();
    connect(clientConnection,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));

    ui->serverStatusLabel->setText(tr("开始传送文件 %1 ！").arg(theFileName));

    localFile = new QFile(fileName);
    if(!localFile->open((QFile::ReadOnly))){//以只读方式打开
        QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return;
    }
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    time.start();
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = TotalBytes - clientConnection->write(outBlock);
    qDebug()<<currentFile<<TotalBytes;
    outBlock.resize(0);
}


void filesend::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0){
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);
    }
    else{
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);

   float useTime = time.elapsed();
   double speed = bytesWritten / useTime;
   ui->serverStatusLabel->setText(tr("已发送 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
                                  .arg(bytesWritten / (1024*1024))//已发送
                                  .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                  .arg(TotalBytes / (1024 * 1024))//总大小
                                  .arg(useTime/1000,0,'f',0)//用时
                                  .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间
    if(bytesWritten == TotalBytes)
        ui->serverStatusLabel->setText(tr("传送文件 %1 成功").arg(theFileName));
}


void filesend::refused()
{
    fileSender->close();
    ui->serverStatusLabel->setText(tr("对方拒绝接收！！！"));
}


void filesend::initSender()//初始化
{
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    ui->progressBar->reset();

    fileSender->close();
}


void filesend::SenderStart(QString file, QString addr)
{
    this->fileName = file;
    this->theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);

    if(!fileSender->listen(QHostAddress::Any,tcpPort))//开始监听
    {
        qDebug() << fileSender->errorString();
        close();
        return;
    }
    ui->serverStatusLabel->setText(tr("等待对方接收... ..."));
    emit sendFileName(theFileName,addr);
   // this->close();
}


void filesend::on_btnQuit_clicked()
{
    if(fileSender->isListening())
        fileSender->close();
    this->close();
}
