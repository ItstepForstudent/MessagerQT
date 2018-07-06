//
// Created by Artur Mamedov on 05.07.2018.
//

#ifndef QTMESSAGER_REQUESTEXECUTOR_H
#define QTMESSAGER_REQUESTEXECUTOR_H


#include <memory>
#include <QString>
#include "../entity/Response.h"
#include "../chatunit/ChatUnit.h"

namespace executors {


    class IRequestExecutor {
    protected:
        ChatUnit* unit;
    public:
        explicit IRequestExecutor(ChatUnit *);
        virtual std::shared_ptr<Response> execute(std::shared_ptr<Request>)=0;
    };


    std::shared_ptr<IRequestExecutor> createRequestExecutor(const QString &,ChatUnit*);

#endif //QTMESSAGER_REQUESTEXECUTOR_H
}