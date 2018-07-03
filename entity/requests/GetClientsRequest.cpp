//
// Created by Artur Mamedov on 03.07.2018.
//

#include "GetClientsRequest.h"

GetClientsRequest::GetClientsRequest(QObject *parent) : Request("GetClients", parent) {}

void GetClientsRequest::writeData(QXmlStreamWriter *writer) const {

}

void GetClientsRequest::readData(QXmlStreamReader *reader) {

}
