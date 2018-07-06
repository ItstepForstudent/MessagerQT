//
// Created by Artur Mamedov on 06.07.2018.
//

#include <altivec.h>
#include "GetClientsExeutor.h"

executors::GetClientsExeutor::GetClientsExeutor(ChatUnit * unit) : IRequestExecutor(unit){
}

std::shared_ptr<Response> executors::GetClientsExeutor::execute(std::shared_ptr<Request> ptr) {
    return std::shared_ptr<Response>();
}
