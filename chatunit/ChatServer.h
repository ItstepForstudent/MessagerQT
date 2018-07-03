//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATSERVER_H
#define QTMESSAGER_CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "../entity/Client.h"

class ChatServer :QObject {
    Q_OBJECT
    QTcpServer *tcpServer;
    QList<Client*> clients;
public:
    ChatServer(QObject* parent=0);
public slots:
    void inputConnecting();
};


#endif //QTMESSAGER_CHATSERVER_H
