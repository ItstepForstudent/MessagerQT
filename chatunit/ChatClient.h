//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_CHATCLIENT_H
#define QTMESSAGER_CHATCLIENT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QTextEdit>
#include <QDataStream>
#include <QMessageBox>
#include<QVBoxLayout>
#include<QLabel>
#include<QTime>
#include <QByteArray>
#include<QLineEdit>
#include <QPushButton>
class ChatClient : public QWidget {
Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit*  m_ptxtInfo;
    QLineEdit*  m_ptxtInput;
public:
    ChatClient(const QString& strHost, int nPort, QWidget* pwgt = 0) ;

private slots:
    void slotReadyRead   (                            );
    void slotError       (QAbstractSocket::SocketError);
    void slotSendToServer(                            );
    void slotConnected   (                            );



};


#endif //QTMESSAGER_CHATCLIENT_H
