//
// Created by Artur Mamedov on 13.07.2018.
//

#ifndef QTMESSAGER_IUNIT_H
#define QTMESSAGER_IUNIT_H


#include <QObject>
#include <memory>
#include "../entity/Client.h"

class IUnit :public QObject {
Q_OBJECT
public:
    virtual void sendMessage(std::shared_ptr<Client> client,QString msg)=0;
    virtual void connectToAddress(QString address) = 0;
    virtual QList<std::shared_ptr<Client>> &getClientsList() =0;
    virtual void setCurrentClientName(QString name) =0;

    IUnit(QObject *parrent =0) :QObject(parrent){}
    virtual ~IUnit() = default;
signals:
    void onLoadingClientList();
    void onMessageSended();
    void onClientConnected(std::shared_ptr<Client>);

};


#endif //QTMESSAGER_IUNIT_H
