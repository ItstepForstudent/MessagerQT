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

   // qDebug()<<data;

    std::shared_ptr<Request> request = Request::createRequest(data);
    std::shared_ptr<Response> response = nullptr;
    incomingRequest(request,response);


    




//        sendToClient(pClientSocket,
//                     "Server Response: Received \"" + str + "\""
//        );
}
