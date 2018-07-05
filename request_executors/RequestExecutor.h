//
// Created by Artur Mamedov on 05.07.2018.
//

#ifndef QTMESSAGER_REQUESTEXECUTOR_H
#define QTMESSAGER_REQUESTEXECUTOR_H


#include <memory>
#include <QString>
#include "../entity/Response.h"

class RequestExecutor {
public:
    virtual std::shared_ptr<Response> execute(std::shared_ptr<Response>)=0;
    static std::shared_ptr<RequestExecutor> create(const QString&);

};


#endif //QTMESSAGER_REQUESTEXECUTOR_H
