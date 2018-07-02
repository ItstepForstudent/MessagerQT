#include "chatunit.h"
#define PORT 8081


ChatUnit::ChatUnit(QObject *parent)
{
    this->pServer = new QTcpServer(this);
    connect(this->pServer,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!this->pServer->listen(QHostAddress::Any, PORT))
        qDebug() << "Server could not start";
    else
        qDebug() << "Server started!";
}

void ChatUnit::newConnection()
{
    QTcpSocket *socket = pServer->nextPendingConnection();
    QHostAddress addr = socket->peerAddress();
    clients.append(addr);


//    socket->write("Hello client\r\n");
//    socket->flush();
//    socket->waitForBytesWritten(3000);
    socket->close();
}


void ChatUnit::testConnecting(){
          QTcpSocket sock;
          sock.connectToHost("127.0.0.1",PORT);
          connect(sock,SIGNAL(connected()),this,SLOT(connectedToServer()));


}

void ChatUnit::connectedToServer(){
    qDebug()<<"connected to server";
}
