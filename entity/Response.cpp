//
// Created by Artur Mamedov on 03.07.2018.
//

#include "Response.h"
#include "responces/GetClientsResponse.h"
Response::Response(const QString &type) :type(type){

}

const QString &Response::getType() const {
    return type;
}

void Response::setType(const QString &type) {
    Response::type = type;
}

const QString Response::toXML() const {
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

std::shared_ptr<Response> Response::createResponse(const QString &xml) {
    QXmlStreamReader reader(xml);
    std::shared_ptr<Response> response;
    if (!reader.readNextStartElement()) return std::shared_ptr<Response>(nullptr);
    if (reader.name() == "response") {
        while (reader.readNextStartElement()) {
            if (reader.name() == "type")
                response = Response::createInstance(reader.readElementText());
            else if (reader.name() == "data") {
                if (response == nullptr) return std::shared_ptr<Response>(nullptr);
                response->readData(&reader);
            } else
                reader.skipCurrentElement();
        }
    }
    return response;
}

std::shared_ptr<Response> Response::createInstance(QString type) {
    if(type == "GetClients")
        return std::shared_ptr<Response>(new GetClientsResponse());
    return std::shared_ptr<Response>();
}


