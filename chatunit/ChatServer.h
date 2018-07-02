//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATSERVER_H
#define QTMESSAGER_CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class ChatServer :QObject {
    Q_OBJECT
    QTcpServer *tcpServer;
public:
    ChatServer(QObject* parent=0);
public slots:
    void inputConnecting();
};


#endif //QTMESSAGER_CHATSERVER_H
