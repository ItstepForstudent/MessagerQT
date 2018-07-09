//
// Created by Artur Mamedov on 09.07.2018.
//

#ifndef QTMESSAGER_MESSAGEEXECUTOR_H
#define QTMESSAGER_MESSAGEEXECUTOR_H

#include "IRequestExecutor.h"
namespace executors {

    class MessageExecutor : public IRequestExecutor {
    public:
        MessageExecutor(ChatUnit *);

        std::shared_ptr<responces::Response> execute(std::shared_ptr<requests::Request>) override;
    };

}
#endif //QTMESSAGER_MESSAGEEXECUTOR_H
