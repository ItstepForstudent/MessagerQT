//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_CHATCLIENT_H
#define QTMESSAGER_CHATCLIENT_H

#include <memory>
#include <QThread>
#include <QWaitCondition>
#include "../entity/Request.h"
#include "../entity/Response.h"
#include "../entity/Client.h"

class ChatClient:QThread {
    Q_OBJECT
    explicit ChatClient(QObject *parent);
    ~ChatClient() override;

public:
    void sendRequest(std::shared_ptr<requests::Request>, std::shared_ptr<Client>) ;

signals:
    void onResponse(std::shared_ptr<responces::Response> responce);

private:
    void run() override;


private:
    std::shared_ptr<Client> toClient;
    QMutex mutex;
    QWaitCondition condition;
    bool quit;
    std::shared_ptr<requests::Request> activeRequest;
};


#endif //QTMESSAGER_CHATCLIENT_H
