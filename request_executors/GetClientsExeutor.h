//
// Created by Artur Mamedov on 06.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSEXEUTOR_H
#define QTMESSAGER_GETCLIENTSEXEUTOR_H

#include "IRequestExecutor.h"

namespace executors {
    class GetClientsExeutor:IRequestExecutor {
    public:
        explicit GetClientsExeutor(ChatUnit *);
        std::shared_ptr<Response> execute(std::shared_ptr<Request> ptr) override;
    };
}


#endif //QTMESSAGER_GETCLIENTSEXEUTOR_H
