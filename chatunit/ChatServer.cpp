//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatServer.h"
#include "ChatUnit.h"

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
    QHostAddress addr = socket->peerAddress();
   // clients.append(addr);


//    socket->write("Hello client\r\n");
//    socket->flush();
//    socket->waitForBytesWritten(3000);
    socket->close();
}
