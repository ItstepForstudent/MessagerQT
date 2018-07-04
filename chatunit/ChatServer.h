//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATSERVER_H
#define QTMESSAGER_CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QDataStream>
#include "../entity/Client.h"

class ChatServer :QObject {
    Q_OBJECT
    QTcpServer *tcpServer;
    qint16 m_nNextBlockSize;

   // QList<Client*> clients;
public:
    ChatServer(QObject* parent=0);
public slots:
    void inputConnecting();
    void slotReadClient();

};


#endif //QTMESSAGER_CHATSERVER_H
