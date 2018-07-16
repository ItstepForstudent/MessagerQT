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

    std::shared_ptr<requests::Request> request = requests::Request::fromXML(data);
    request->setAddress(pClientSocket->peerAddress());
    QString response;
    incomingRequest(request,response);

    //send responce
    sendToClient(response,pClientSocket);
    pClientSocket->disconnect();

}

void ChatServer::sendToClient(QString xmldata, QTcpSocket *tcpSocket) {
    qDebug()<<"send:"<<xmldata;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << quint32(0) << xmldata;
    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));
    tcpSocket->write(arrBlock);
    tcpSocket->flush();
}
