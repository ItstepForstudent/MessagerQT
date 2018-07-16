//
// Created by Artur Mamedov on 02.07.2018.
//

#ifndef QTMESSAGER_CHATUNIT_H
#define QTMESSAGER_CHATUNIT_H


#include <QtGlobal>
#include "ChatServer.h"
#include "ChatClient.h"
#include "IUnit.h"
#include <memory>
#include<QString>


class ChatUnit:public IUnit {
    Q_OBJECT
    ChatServer *server;
    ChatClient *client;
    QList<std::shared_ptr<Client>> clientList;
    QString name = "anonimus";
public:
    explicit ChatUnit(QObject* parent=0);
    static const quint16 PORT;

    void connectToAddress(QString address) override;

    void setCurrentClientName(QString name) override;

    void sendMessage(std::shared_ptr<Client> client, QString msg) override;
    QList<std::shared_ptr<Client>> &getClientsList() override;

    void addClient(const std::shared_ptr<Client>&);


    void clientConnected(std::shared_ptr<Client>);

private slots:
    void recognizeRequest(std::shared_ptr<requests::Request>,QString &);

};


#endif //QTMESSAGER_CHATUNIT_H
