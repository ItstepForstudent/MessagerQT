//
// Created by Artur Mamedov on 03.07.2018.
//

#include <QTcpSocket>
#include <QDataStream>
#include "ChatClient.h"
#include "ChatUnit.h"

void ChatClient::sendRequest(std::shared_ptr<requests::Request> request, std::shared_ptr<Client> client) {
    mutex.lock();
    this->activeRequest = std::move(request);
    this->toClient = std::move(client);
    if (!isRunning()) start();
    else condition.wakeOne();
    mutex.unlock();
}

ChatClient::ChatClient(QObject *parent) : QThread(parent) {

}

ChatClient::~ChatClient() {
    mutex.lock();
    quit = true;
    condition.wakeOne();
    mutex.unlock();
    wait();
}

void ChatClient::run() {

    const int TIMEOUT = 3000;

    mutex.lock();
    std::shared_ptr<Client> client = toClient;
    std::shared_ptr<requests::Request> request = activeRequest;
    mutex.unlock();


    QTcpSocket socket;
    socket.connectToHost(client->getAddress(), ChatUnit::PORT);

    if(!socket.waitForConnected(TIMEOUT)){
        //TODO:: send error signal
        return;
    }

    //Send data to server:
    QString xmlData = request->toXML();

    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out<<qint32(0)<<xmlData;
    out.device()->seek(0);
    out<<qint32(data.size() - sizeof(qint32));

    socket.write(data);

    if(!socket.waitForReadyRead(TIMEOUT)){
        //TODO:: emit error
        return;
    }


    //Read server responce:
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_5_11);

    qint32 size;
    in>>size;

    if (socket.bytesAvailable() < sizeof(quint32)) {
        //TODO:: emit error
        return;
    }
    in >> size;
    if (socket.bytesAvailable() < size) {
        //TODO:: emit error
        return;
    }

    in>>data;

    std::shared_ptr<responces::Response> responce = responces::Response::fromXML(data);

    mutex.lock();
    emit onResponse(responce);

    condition.wait(&mutex);
    toClient = client;
    activeRequest = request;
    mutex.unlock();





}
