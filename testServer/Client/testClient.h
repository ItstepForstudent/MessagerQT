//
// Created by Admin on 04.07.2018.
//

#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H


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

class testClient : public QWidget {
Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit*  m_ptxtInfo;
    QLineEdit*  m_ptxtInput;
    quint16     m_nNextBlockSize;

public:
    testClient(const QString& strHost, int nPort, QWidget* pwgt = 0) ;

private slots:
    void slotReadyRead   (                            );
    void slotError       (QAbstractSocket::SocketError);
    void slotSendToServer(                            );
    void slotConnected   (                            );
};


#endif //TEST_CLIENT_H
