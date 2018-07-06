//
// Created by Artur Mamedov on 06.07.2018.
//

#include "GetClientsExeutor.h"

executors::GetClientsExeutor::GetClientsExeutor(ChatUnit * unit) : IRequestExecutor(unit){
}

std::shared_ptr<responces::Response> executors::GetClientsExeutor::execute(std::shared_ptr<requests::Request> ptr) {
    return std::shared_ptr<responces::Response>();
}
