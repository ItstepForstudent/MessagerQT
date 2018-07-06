//
// Created by Artur Mamedov on 02.07.2018.
//

#include <QDataStream>
#include "ChatServer.h"
#include "ChatUnit.h"
#include "../entity/Request.h"

ChatServer::ChatServer(QObject *parent) : QObject(parent) {
    tcpServer = new QTcpServer(this);
    connect(this->tcpServer,SIGNAL(newConnection()),this,SLOT(inputConnecting()));
    if(!this->tcpServer->listen(QHostAddress::Any, ChatUnit::PORT))
        qDebug() << "Server could not start";
    else
        qDebug() << "Server started!";
}

void ChatServer::inputConnecting() {
    QTcpSocket *socket = tcpServer->nextPendingConnection();
    qDebug()<<"incoming data";
    //QHostAddress addr = socket->peerAddress();


    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readingClient()));



   // clients.append(addr);
//    socket->write("Hello client\r\n");
//    socket->flush();
//    socket->waitForBytesWritten(3000);
//    socket->close();
}

/*
void ChatServer::readingClient() {
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_11);
    //reading a size of data
    qint32 size;
    if (pClientSocket->bytesAvailable() < sizeof(quint32)) {
        pClientSocket->disconnect();
        return;
    }
    in >> size;
    qDebug()<<size;
    if (pClientSocket->bytesAvailable() < size) {
        pClientSocket->disconnect();
        return;
    }

    QString data;
    in>>data;

   // qDebug()<<data;

  /*  std::shared_ptr<Request> request = Request::createRequest(data);
   std::shared_ptr<Response> response = nullptr;
    incomingRequest(request,response);

*/
    




//        sendToClient(pClientSocket,
//                     "Server Response: Received \"" + str + "\""
//        );
        //}
void ChatServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);
}


void ChatServer::readingClient()
{   qint16  m_nNextBlockSize = 0;
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_11);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QTime   time;
        QString str;
        in >> time >> str;

        QString strMessage =
                time.toString() + " " + "Client has sended - " + str;
       // m_ptxt->append(strMessage);
        qDebug()<<strMessage;
        m_nNextBlockSize = 0;

        sendToClient(pClientSocket,
                     "Server Response: Received \"" + str + "\""
        );
    }
}
