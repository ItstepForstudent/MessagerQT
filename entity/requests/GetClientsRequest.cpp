//
// Created by Artur Mamedov on 03.07.2018.
//

#include "GetClientsRequest.h"

GetClientsRequest::GetClientsRequest() : Request("GetClients") {}

void GetClientsRequest::writeData(QXmlStreamWriter *writer) const {
    writer->writeTextElement("name",name);
}

void GetClientsRequest::readData(QXmlStreamReader *reader) {
    if(reader->readNextStartElement()){
        if(reader->name() == "name")
            this->name = reader->readElementText();
        else
            reader->skipCurrentElement();
    }
}

void GetClientsRequest::setName(const QString &name) {
    GetClientsRequest::name = name;
}

const QString &GetClientsRequest::getName() const {
    return name;
}

