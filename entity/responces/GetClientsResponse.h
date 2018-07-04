//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSRESPONSE_H
#define QTMESSAGER_GETCLIENTSRESPONSE_H


#include "../Response.h"
#include "../Client.h"

class GetClientsResponse: Response {
    QList<std::shared_ptr<Client>> clients;
public:
    void addClient(std::shared_ptr<Client> client);
    GetClientsResponse();

};


#endif //QTMESSAGER_GETCLIENTSRESPONSE_H
