//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatUnit.h"
#include "../entity/requests/GetClientsRequest.h"
#include "../entity/responces/GetClientsResponse.h"
#include "../request_executors/IRequestExecutor.h"
#include "../entity/requests/MessageRequest.h"

const quint16 ChatUnit::PORT = 8081;

ChatUnit::ChatUnit(QObject *parent) : IUnit(parent) {
    this->server = new ChatServer(this);
    this->client = new ChatClient(this);
    connect(
            this->server,
            SIGNAL(incomingRequest(std::shared_ptr<requests::Request>, QString & )),
            this,
            SLOT(recognizeRequest(std::shared_ptr<requests::Request>, QString & )),
            Qt::DirectConnection
    );
}

void ChatUnit::recognizeRequest(std::shared_ptr<requests::Request> request, QString &xmlResponse) {
    qDebug() << "Request received";
    const QString &type = request->getType();
    qDebug() << type;
    std::shared_ptr<executors::IRequestExecutor> executor = executors::createRequestExecutor(type, this);
    xmlResponse = executor->execute(request)->toXML();
}

void ChatUnit::addClient(const std::shared_ptr<Client> &c) { this->clientList.append(c); }

QList<std::shared_ptr<Client>> &ChatUnit::getClientsList() {
    return clientList;
}


void ChatUnit::sendMessage(std::shared_ptr<Client> client, QString msg) {
    auto req = std::shared_ptr<requests::MessageRequest>(new requests::MessageRequest());
    req->setMessage(msg);
    this->client->sendRequest(req, client, [](std::shared_ptr<responces::Response> resp) {
        emit onMessageSended();
    });
}


void ChatUnit::setCurrentClientName(QString name) {
    this->name = name;
}

void ChatUnit::connectToAddress(QString address) {
    auto request = std::shared_ptr<requests::GetClientsRequest>(new requests::GetClientsRequest());
    request->setName(this->name);
    this->client->sendRequest(
            request, std::shared_ptr<Client>(new Client("", QHostAddress(address))),
            [](std::shared_ptr<responces::Response> resp) {
                this->clientList = reinterpret_cast<responces::GetClientsResponse &>(*resp).getClients();
                emit onLoadingClientList();
            }
    );
}

void ChatUnit::clientConnected(std::shared_ptr<Client> client) {
    emit onClientConnected(client);
}