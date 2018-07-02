//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATUNIT_H
#define QTMESSAGER_CHATUNIT_H


#include <QtGlobal>
#include "ChatServer.h"

class ChatUnit:public QObject {
    ChatServer *server;
public:
    ChatUnit(QObject* parent=0);
    static const quint16 PORT;
};


#endif //QTMESSAGER_CHATUNIT_H
