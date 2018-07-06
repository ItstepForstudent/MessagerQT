//
// Created by Artur Mamedov on 03.07.2018.
//

#include "GetClientsRequest.h"

requests::GetClientsRequest::GetClientsRequest() : Request("GetClients") {}

void requests::GetClientsRequest::writeData(QXmlStreamWriter *writer) const {
    writer->writeTextElement("name",name);
}

void requests::GetClientsRequest::readData(QXmlStreamReader *reader) {
    if(reader->readNextStartElement()){
        if(reader->name() == "name")
            this->name = reader->readElementText();
        else
            reader->skipCurrentElement();
    }
}

void requests::GetClientsRequest::setName(const QString &name) {
    GetClientsRequest::name = name;
}

const QString &requests::GetClientsRequest::getName() const {
    return name;
}

