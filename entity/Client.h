    //
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_CLIENT_H
#define QTMESSAGER_CLIENT_H


#include <QObject>
#include <QHostAddress>
#include <utility>

class Client{
    QString name;
    QHostAddress address;
public:
    Client(QString name, const QHostAddress &address)
            :  name(std::move(name)), address(address) {}

    const QString &getName() const {
        return name;
    }

    const QHostAddress &getAddress() const {
        return address;
    }
};


#endif //QTMESSAGER_CLIENT_H
