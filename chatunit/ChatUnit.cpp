//
// Created by Artur Mamedov on 02.07.2018.
//

#include "ChatUnit.h"
const quint16 ChatUnit::PORT=8081;

ChatUnit::ChatUnit(QObject *parent) : QObject(parent) {
    this->server = new ChatServer(this);
}
