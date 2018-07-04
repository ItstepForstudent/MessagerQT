#include "Request.h"
#include <QDebug>
#include "requests/GetClientsRequest.h"





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

std::shared_ptr<Request> Request::createRequest(const QString &xml) {
    QXmlStreamReader reader(xml);
    std::shared_ptr<Request> request;
    if (!reader.readNextStartElement()) return std::shared_ptr<Request>(nullptr);
    if (reader.name() == "request") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                request = Request::createInstance(reader.readElementText());
            else if (reader.name() == "data") {
                if (request == nullptr) return std::shared_ptr<Request>(nullptr);
                request->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return request;
}

std::shared_ptr<Request> Request::createInstance(QString type) {
    if (type == "GetClients") return std::shared_ptr<Request>(new GetClientsRequest());
    return nullptr;
}

const QString &Request::getType() const { return type; }
void Request::setType(const QString &type) { Request::type = type; }

Request::Request(const QString &type):type(type) {

}


