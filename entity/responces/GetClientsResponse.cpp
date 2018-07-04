//
// Created by Artur Mamedov on 03.07.2018.
//

#include "GetClientsResponse.h"

GetClientsResponse::GetClientsResponse() : Response("GetClients") {}

void GetClientsResponse::addClient(std::shared_ptr<Client> client) {
    this->clients.append(client);
}

void GetClientsResponse::writeData(QXmlStreamWriter *writer) const {
    writer->writeStartElement("clients");
    for (auto client:this->clients){
        writer->writeStartElement("client");
        writer->writeTextElement("name",client->getName());
        writer->writeTextElement("addr",client->getAddress().toString());
        writer->writeEndElement();
    }
    writer->writeEndElement();
}

void GetClientsResponse::readData(QXmlStreamReader *reader) {

}


