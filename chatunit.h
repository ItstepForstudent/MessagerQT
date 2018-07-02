#ifndef CHATUNIT_H
#define CHATUNIT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QVector>

class ChatUnit:QObject
{
    Q_OBJECT
    QTcpServer *pServer;
    QVector<QHostAddress> clients;

public:
   explicit ChatUnit(QObject *parent = 0);
    void testConnecting();


signals:

public slots:
    void newConnection();
    void connectedToServer();

private:
    QTcpServer *server;
};

#endif // CHATUNIT_H
