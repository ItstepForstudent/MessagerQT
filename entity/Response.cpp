//
// Created by Artur Mamedov on 03.07.2018.
//

#include "Response.h"
#include "responces/GetClientsResponse.h"
#include "responces/MessageResponse.h"
responces::Response::Response(const QString &type) :type(type){

}

const QString &responces::Response::getType() const {
    return type;
}

void responces::Response::setType(const QString &type) {
    Response::type = type;
}

const QString responces::Response::toXML() const {
    QString data;
    QXmlStreamWriter streamWriter(&data);
    streamWriter.setAutoFormatting(false);
    streamWriter.writeStartDocument();

    streamWriter.writeStartElement("response");

    streamWriter.writeStartElement("type");
    streamWriter.writeCharacters(this->type);
    streamWriter.writeEndElement();

    streamWriter.writeStartElement("data");
    this->writeData(&streamWriter);
    streamWriter.writeEndElement();

    streamWriter.writeEndElement();

    return data;
}

std::shared_ptr<responces::Response> responces::Response::fromXML(const QString &xml) {
    QXmlStreamReader reader(xml);
    std::shared_ptr<Response> response;
    if (!reader.readNextStartElement()) return std::shared_ptr<Response>(nullptr);
    if (reader.name() == "response") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                response = Response::createInstance(reader.readElementText());
            else if (reader.name() == "data") {
                if (response == nullptr) return std::shared_ptr<responces::Response>(nullptr);
                response->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return response;
}

std::shared_ptr<responces::Response> responces::Response::createInstance(QString type) {
    if(type == "GetClients") return std::shared_ptr<responces::Response>(new GetClientsResponse());
    if(type == "Message") return std::shared_ptr<responces::Response>(new MessageResponse());

    return std::shared_ptr<responces::Response>();
}


