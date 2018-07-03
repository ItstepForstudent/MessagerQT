#include "Request.h"
#include "requests/GetClientsRequest.h"


Request::Request(const QString &type) : type(type) {}

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


Request *Request::createRequest(const QString& xml) {
    QXmlStreamReader reader(xml);
    Request *request = nullptr;
    if (!reader.readNextStartElement()) return nullptr;
    if (reader.name() == "request") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                request = Request::createInstance(reader.readElementText());
            if (reader.name() == "data") {
                if (request == nullptr) return nullptr;
                request->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return nullptr;
}

Request *Request::createInstance(QString type) {
    if (type == "GetClients") return new GetClientsRequest();

    return nullptr;
}

