//
// Created by Artur Mamedov on 03.07.2018.
//

#include <QTcpSocket>
#include <QDataStream>
#include "ChatClient.h"
#include "ChatUnit.h"

void ChatClient::sendRequest(std::shared_ptr<requests::Request> request, std::shared_ptr<Client> client,
                             std::function<void(std::shared_ptr<responces::Response>)> onResponce) {
    std::thread th([&]() {
        this->run(request, client, [](const std::shared_ptr<responces::Response> resp){
            auto x=resp;
            qDebug()<<x->toXML();
        });
    });

    th.detach();
}

ChatClient::ChatClient(QObject *parent) : QObject(parent) {

}

ChatClient::~ChatClient() {}

void ChatClient::run(
        std::shared_ptr<requests::Request> request,
        std::shared_ptr<Client> client,
        std::function<void(std::shared_ptr<responces::Response>)> onResponce
) {
    qDebug() << "Request running";
    const int TIMEOUT = 3000;


    QTcpSocket socket;
    socket.connectToHost(client->getAddress(), ChatUnit::PORT);
    qDebug() << client->getAddress();
    if (!socket.waitForConnected(TIMEOUT)) {
        //TODO:: send error signal
        qDebug() << "Connect timeout";
        return;
    }
    qDebug() << "Connected";

    //Send data to server:
    QString xmlData = request->toXML();

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << qint32(0) << xmlData;
    out.device()->seek(0);
    out << qint32(data.size() - sizeof(qint32));

    socket.write(data);

    if (!socket.waitForReadyRead(TIMEOUT)) {
        //TODO:: emit error
        qDebug() << "Send data error";
        return;
    }


    //Read server responce:
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_5_11);
    qint32 size;

    if (socket.bytesAvailable() < sizeof(quint32)) {
        //TODO:: emit error
        return;
    }
    in >> size;
    qDebug()<<size;
    if (socket.bytesAvailable() < size) {
        //TODO:: emit error
        return;
    }

    QString receivedXML;
    in >> receivedXML;
    qDebug()<<receivedXML;

    std::shared_ptr<responces::Response> responce = responces::Response::fromXML(receivedXML);


    onResponce(responce);







}
