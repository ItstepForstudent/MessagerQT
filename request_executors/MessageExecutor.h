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

    };

}
#endif //QTMESSAGER_MESSAGEEXECUTOR_H
