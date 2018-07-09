//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatUnit.h"
#include "../entity/requests/GetClientsRequest.h"
#include "../entity/responces/GetClientsResponse.h"
#include "../request_executors/IRequestExecutor.h"

const quint16 ChatUnit::PORT=8081;

ChatUnit::ChatUnit(QObject *parent) : QObject(parent) {
    this->server = new ChatServer(this);

    connect(
            this->server,
            SIGNAL(incomingRequest(std::shared_ptr<requests::Request>,QString&)),
            this,
            SLOT(recognizeRequest(std::shared_ptr<requests::Request>,QString&)),
            Qt::DirectConnection
    );
}

void ChatUnit::recognizeRequest(std::shared_ptr<requests::Request> request, QString &xmlResponse) {
    const QString &type = request->getType();
    std::shared_ptr<executors::IRequestExecutor> executor = executors::createRequestExecutor(type,this);
    xmlResponse = executor->execute(request)->toXML();
}


void ChatUnit::setClientList(const QList<std::shared_ptr<Client>> &clientList) {
    ChatUnit::clientList = clientList;
}

const QList<std::shared_ptr<Client>> &ChatUnit::getClientList() const {
    return clientList;
}

void ChatUnit::addClient(const std::shared_ptr<Client> &c) {
    this->clientList.append(c);
}




//
