//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATUNIT_H
#define QTMESSAGER_CHATUNIT_H


#include <QtGlobal>
#include "ChatServer.h"
#include "ChatClient.h"
#include <memory>

class ChatUnit:public QObject {
    Q_OBJECT
    ChatServer *server;
    ChatClient *client;
    QList<std::shared_ptr<Client>> clientList;



    std::shared_ptr<responces::Response> getClientsRequestProcessing(std::shared_ptr<requests::Request>);


public:
    ChatUnit(QObject* parent=0);
    static const quint16 PORT;

    void setClientList(const QList<std::shared_ptr<Client>> &clientList);
    const QList<std::shared_ptr<Client>> &getClientList() const;
    void addClient(const std::shared_ptr<Client>&);

private slots:
    void recognizeRequest(std::shared_ptr<requests::Request>,std::shared_ptr<responces::Response>&);
};


#endif //QTMESSAGER_CHATUNIT_H
