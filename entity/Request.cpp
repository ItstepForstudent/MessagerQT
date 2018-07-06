#include "Request.h"
#include <QDebug>
#include "requests/GetClientsRequest.h"


const QString requests::Request::toXML() const {
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

std::shared_ptr<requests::Request> requests::Request::fromXML(const QString &xml) {
    QXmlStreamReader reader(xml);
    std::shared_ptr<Request> request;
    if (!reader.readNextStartElement()) return std::shared_ptr<Request>(nullptr);
    if (reader.name() == "request") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                request = requests::Request::createInstance(reader.readElementText());
            else if (reader.name() == "data") {
                if (request == nullptr) return std::shared_ptr<requests::Request>(nullptr);
                request->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return request;
}

std::shared_ptr<requests::Request> requests::Request::createInstance(QString type) {
    if (type == "GetClients") return std::shared_ptr<requests::Request>(new GetClientsRequest());
    return nullptr;
}

const QString &requests::Request::getType() const { return type; }

void requests::Request::setType(const QString &type) { requests::Request::type = type; }

requests::Request::Request(const QString &type) : type(type) {

}

const QHostAddress &requests::Request::getAddress() const {
    return address;
}

void requests::Request::setAddress(const QHostAddress &address) {
    Request::address = address;
}


