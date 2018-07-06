//
// Created by Artur Mamedov on 06.07.2018.
//

#include "GetClientsExeutor.h"
#include "../entity/requests/GetClientsRequest.h"
#include "../entity/responces/GetClientsResponse.h"

executors::GetClientsExeutor::GetClientsExeutor(ChatUnit * unit) : IRequestExecutor(unit){}

std::shared_ptr<responces::Response> executors::GetClientsExeutor::execute(std::shared_ptr<requests::Request> _request) {
    auto request = reinterpret_cast<typename std::shared_ptr<requests::GetClientsRequest>::element_type*>(_request.get());

    auto * response = new responces::GetClientsResponse();

    for(const auto &client: unit->getClientList()){
        if(client->getAddress()==request->getAddress()) continue;
        response->addClient(client);
    }

    std::shared_ptr<Client> client(new Client(request->getName(),request->getAddress()));
    unit->addClient(client);

    return std::shared_ptr<responces::Response>(response);
}
