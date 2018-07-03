//
// Created by Artur Mamedov on 03.07.2018.
//

#include <QXmlStreamWriter>
#include "Request.h"
#include "requests/GetClientsRequest.h"

Request::Request(const QString &type, QObject *parent) : QObject(parent), type(type) {}

const QString &Request::getType() const {
    return type;
}

void Request::setType(const QString &type) {
    Request::type = type;
}

const QString Request::toXML() const {
    QString data;
    QXmlStreamWriter streamWriter(&data);
    streamWriter.setAutoFormatting(false);
    streamWriter.writeStartDocument();

    streamWriter.writeStartElement("request");

    streamWriter.writeStartElement("type");
    streamWriter.writeCharacters(this->type);
    streamWriter.writeEndElement();

    streamWriter.writeStartElement("data");
    this->writeData(&streamWriter);
    streamWriter.writeEndElement();

    streamWriter.writeEndElement();


    return data;
}


Request *Request::createRequest(const QString& xml, QObject *parent) {
    QXmlStreamReader reader(xml);
    Request *request = nullptr;
    if (!reader.readNextStartElement()) return nullptr;
    if (reader.name() == "request") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                request = Request::createInstance(reader.readElementText(), parent);
            if (reader.name() == "data") {
                if (request == nullptr) return nullptr;
                request->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return nullptr;
}

Request *Request::createInstance(QString type, QObject *pObject) {
    if (type == "GetClients") return new GetClientsRequest(pObject);
    return nullptr;
}

