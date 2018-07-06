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

class ChatServer :public QObject {
    Q_OBJECT
    QTcpServer *tcpServer;
    QList<Client*> clients;
public:
    ChatServer(QObject* parent=0);
    void ChatServer::sendToClient(QTcpSocket* pSocket, const QString& str);

signals:
    void incomingRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&);


public slots:
    void inputConnecting();
    void readingClient();
};


#endif //QTMESSAGER_CHATSERVER_H
