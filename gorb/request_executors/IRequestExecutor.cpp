//
// Created by Artur Mamedov on 05.07.2018.
//

#include "IRequestExecutor.h"
#include "GetClientsExeutor.h"
#include "MessageExecutor.h"

std::shared_ptr<executors::IRequestExecutor> executors::createRequestExecutor(const QString &type, ChatUnit* unit) {
    if(type=="GetClients") return std::shared_ptr<IRequestExecutor>(new executors::GetClientsExeutor(unit));
    if(type=="Message") return std::shared_ptr<IRequestExecutor>(new executors::MessageExecutor(unit));
    return std::shared_ptr<IRequestExecutor>();
}



executors::IRequestExecutor::IRequestExecutor(ChatUnit * _unit):unit(_unit){}
