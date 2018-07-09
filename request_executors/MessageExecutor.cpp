//
// Created by Artur Mamedov on 09.07.2018.
//

#include "MessageExecutor.h"

executors::MessageExecutor::MessageExecutor(ChatUnit *unit) : IRequestExecutor(unit){
}

std::shared_ptr<responces::Response> executors::MessageExecutor::execute(std::shared_ptr<requests::Request> _request) {
    return std::shared_ptr<responces::Response>();
}
