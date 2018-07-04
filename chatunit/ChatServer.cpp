//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatServer.h"
#include "ChatUnit.h"

ChatServer::ChatServer(QObject *parent) : QObject(parent), m_nNextBlockSize(0){
    tcpServer = new QTcpServer(this);
    connect(this->tcpServer,SIGNAL(newConnection()),this,SLOT(inputConnecting()));
    if(!this->tcpServer->listen(QHostAddress::Any, ChatUnit::PORT))
        qDebug() << "Server could not start";
    else
        qDebug() << "Server started!";
}

void ChatServer::inputConnecting() {
    QTcpSocket *pClientSocket = tcpServer->nextPendingConnection();

    connect(pClientSocket, SIGNAL(disconnected()), pClientSocket,SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    //QHostAddress addr = socket->peerAddress();
   // clients.append(addr);


//    socket->write("Hello client\r\n");
//    socket->flush();
//    socket->waitForBytesWritten(3000);
    //socket->close();
}

void ChatServer ::  slotReadClient()
{   QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_11);
    for(;;)
    {
        if(!m_nNextBlockSize)
        {
            if(pClientSocket->bytesAvailable() < sizeof(qint16))
                break;
            in >> m_nNextBlockSize;
        }
        if(pClientSocket->bytesAvailable() < m_nNextBlockSize)
            break;
        QString str;
        in>> str;
        qDebug()<<str;
        m_nNextBlockSize = 0;

    }


}
