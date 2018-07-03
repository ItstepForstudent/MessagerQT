//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSREQUEST_H
#define QTMESSAGER_GETCLIENTSREQUEST_H


#include <QXmlStreamWriter>
#include "../Request.h"

class GetClientsRequest: Request {
public:
    GetClientsRequest(QObject *parent);

private:
    void writeData(QXmlStreamWriter *writer) const override;

    void readData(QXmlStreamReader *reader) override;
};


#endif //QTMESSAGER_GETCLIENTSREQUEST_H
