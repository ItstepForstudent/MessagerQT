//
// Created by Artur Mamedov on 06.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSEXEUTOR_H
#define QTMESSAGER_GETCLIENTSEXEUTOR_H

#include "IRequestExecutor.h"

namespace executors {
    class GetClientsExeutor : public IRequestExecutor {
    public:
        explicit GetClientsExeutor(ChatUnit *);

        std::shared_ptr<responces::Response> execute(std::shared_ptr<requests::Request> ptr) override;
    };
}


#endif //QTMESSAGER_GETCLIENTSEXEUTOR_H
