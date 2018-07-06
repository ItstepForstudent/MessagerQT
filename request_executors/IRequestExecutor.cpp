//
// Created by Artur Mamedov on 05.07.2018.
//

#include "IRequestExecutor.h"
#include "GetClientsExeutor.h"

std::shared_ptr<executors::IRequestExecutor> executors::createRequestExecutor(const QString &type, ChatUnit* unit) {
    if(type=="GetClient") return std::shared_ptr<IRequestExecutor>(new GetClientsExeutor(unit));
    return std::shared_ptr<IRequestExecutor>();
}

executors::IRequestExecutor::IRequestExecutor(ChatUnit * _unit):unit(_unit){}
