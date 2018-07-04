//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_CHATCLIENT_H
#define QTMESSAGER_CHATCLIENT_H


#include <QtNetwork/QTcpSocket>
#include <QTcpServer>
#include <QTcpSocket>
class ChatClient : public QWidget{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    qint16 m_nNextBlockSize;

public:
    ChatClient(const QString& strHost, int nPort);

private slots:
    void SlotReadyRead(    );
    void slotError (QAbstractSocket:: SocketError);
    void slotSendToserver(  );
    void slotConnected ( );


};


#endif //QTMESSAGER_CHATCLIENT_H
