//
// Created by Artur Mamedov on 03.07.2018.
//


#include "GetClientsResponse.h"

responces::GetClientsResponse::GetClientsResponse() : Response("GetClients") {}

void responces::GetClientsResponse::addClient(std::shared_ptr<Client> client) {
    this->clients.append(client);
}

void responces::GetClientsResponse::writeData(QXmlStreamWriter *writer) const {
    writer->writeStartElement("clients");
    for (auto client:this->clients){
        writer->writeStartElement("client");
        writer->writeTextElement("name",client->getName());
        writer->writeTextElement("addr",client->getAddress().toString());
        writer->writeEndElement();
    }
    writer->writeEndElement();
}

void responces::GetClientsResponse::readData(QXmlStreamReader *reader) {
    if(reader->readNextStartElement()){
        if(reader->name() == "clients")
            while(reader->readNextStartElement()){
                if(reader->name() == "client"){
                    QString name,addr;
                    while(reader->readNextStartElement()){
                        if(reader->name() == "name"){
                            name = reader->readElementText();
                        } else if(reader->name() == "addr"){
                            addr = reader->readElementText();
                        }
                        else
                            reader->skipCurrentElement();
                    }
                    if(name!=""&&addr!=""){
                        this->clients.append(std::shared_ptr<Client>(new Client(name,QHostAddress(addr))));
                    }

                }
                else
                    reader->skipCurrentElement();
            }

        else
            reader->skipCurrentElement();
    }






}

const QList<std::shared_ptr<Client>> &responces::GetClientsResponse::getClients() const {
    return clients;
}

void responces::GetClientsResponse::setClients(const QList<std::shared_ptr<Client>> &clients) {
    this->clients = clients;
}

responces::GetClientsResponse::~GetClientsResponse() {
    qDebug()<<"Die";
}


