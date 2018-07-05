//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATUNIT_H
#define QTMESSAGER_CHATUNIT_H


#include <QtGlobal>
#include "ChatServer.h"
#include "ChatClient.h"

class ChatUnit:public QObject {
    Q_OBJECT
    ChatServer *server;
    ChatClient *client;
public:
    ChatUnit(QObject* parent=0);
    static const quint16 PORT;
private slots:
    void recognizeRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&);
};


#endif //QTMESSAGER_CHATUNIT_H
