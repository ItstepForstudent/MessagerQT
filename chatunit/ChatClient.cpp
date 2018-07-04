//
// Created by Artur Mamedov on 03.07.2018.
//

#include "ChatClient.h"

ChatClient::ChatClient(const QString& strHost, int nPort): m_nNextBlockSize(0)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL())
}