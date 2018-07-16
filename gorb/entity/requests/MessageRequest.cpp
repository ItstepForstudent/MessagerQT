//
// Created by Artur Mamedov on 09.07.2018.
//

#include "MessageRequest.h"

requests::MessageRequest::MessageRequest() : Request("Message") {}

const QString &requests::MessageRequest::getMessage() const {
    return message;
}

void requests::MessageRequest::setMessage(const QString &message) {
    MessageRequest::message = message;
}

void requests::MessageRequest::writeData(QXmlStreamWriter *writer) const {
    writer->writeTextElement("message", message);
}

void requests::MessageRequest::readData(QXmlStreamReader *reader) {
    if (reader->readNextStartElement()) {
        if (reader->name() == "message")
            this->message = reader->readElementText();
        else
            reader->skipCurrentElement();
    }
}
