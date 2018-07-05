//
// Created by Artur Mamedov on 05.07.2018.
//

#include "RequestExecutor.h"

std::shared_ptr<RequestExecutor> RequestExecutor::create(const QString &type) {
    if(type=="GetClient") return std::shared_ptr<RequestExecutor>();

    return std::shared_ptr<RequestExecutor>();
}
