//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATSERVER_H
#define QTMESSAGER_CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "../entity/Client.h"
#include "../entity/Request.h"
#include "../entity/Response.h"
#include <memory>

class ChatServer :public QObject {
    Q_OBJECT
    QTcpServer *tcpServer;

    void sendToClient(QString xmldata,QTcpSocket* tcpSocket);

public:
    ChatServer(QObject* parent=0);

signals:
    void incomingRequest(std::shared_ptr<requests::Request>,QString&);
    void newClient();
public slots:
    void inputConnecting();
    void readingClient();
};


#endif //QTMESSAGER_CHATSERVER_H
