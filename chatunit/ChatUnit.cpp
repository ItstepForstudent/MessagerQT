//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatUnit.h"
const quint16 ChatUnit::PORT=8081;

ChatUnit::ChatUnit(QObject *parent) : QObject(parent) {
    this->server = new ChatServer(this);

    connect(
            this->server,
            SIGNAL(incomingRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&)),
            this,
            SLOT(recognizeRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&)),
            Qt::DirectConnection
    );
}

void ChatUnit::recognizeRequest(std::shared_ptr<Request> request, std::shared_ptr<Response> &response) {
    qDebug()<<request->getType();
}




//
