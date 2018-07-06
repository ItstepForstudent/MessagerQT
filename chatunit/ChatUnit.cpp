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
            SIGNAL(incomingRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&)),
            this,
            SLOT(recognizeRequest(std::shared_ptr<Request>,std::shared_ptr<Response>&)),
            Qt::DirectConnection
    );
}

void ChatUnit::recognizeRequest(std::shared_ptr<Request> request, std::shared_ptr<Response> &response) {
    const QString &type = request->getType();
    std::shared_ptr<executors::IRequestExecutor> executor = executors::createRequestExecutor(type,this);
    response = executor->execute(request);
}

std::shared_ptr<Response> ChatUnit::getClientsRequestProcessing(std::shared_ptr<Request> _request) {
    auto request = reinterpret_cast<typename std::shared_ptr<GetClientsRequest>::element_type*>(_request.get());
    std::shared_ptr<GetClientsResponse> response (new GetClientsResponse());




    return std::shared_ptr<Response>();
}

void ChatUnit::setClientList(const QList<std::shared_ptr<Client>> &clientList) {
    ChatUnit::clientList = clientList;
}

const QList<std::shared_ptr<Client>> &ChatUnit::getClientList() const {
    return clientList;
}




//
