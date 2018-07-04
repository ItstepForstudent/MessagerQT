//
// Created by Artur Mamedov on 03.07.2018.
//

#include "GetClientsResponse.h"

GetClientsResponse::GetClientsResponse() : Response("GetClients") {}

void GetClientsResponse::addClient(std::shared_ptr<Client> client) {
    this->clients.append(client);
}


