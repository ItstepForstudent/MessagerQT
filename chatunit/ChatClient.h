//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_CHATCLIENT_H
#define QTMESSAGER_CHATCLIENT_H

#include <memory>
#include <thread>
#include <functional>

#include <QWaitCondition>
#include "../entity/Request.h"
#include "../entity/Response.h"
#include "../entity/Client.h"

class ChatClient:public QObject {
    void run(std::shared_ptr<requests::Request> request,
             std::shared_ptr<Client> client,
             std::function<void(std::shared_ptr<responces::Response>)>);
public:
    explicit ChatClient(QObject *parent);
    void sendRequest(std::shared_ptr<requests::Request>, std::shared_ptr<Client>,std::function<void(std::shared_ptr<responces::Response>)>) ;

    ~ChatClient() override ;
};


#endif //QTMESSAGER_CHATCLIENT_H
