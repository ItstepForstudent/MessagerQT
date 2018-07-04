

#ifndef TEST_SERVER_H
#define TEST_SERVER_H

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

class testServer : public QWidget {
Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit*  m_ptxt;
    quint16     m_nNextBlockSize;

private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);

public:
    testServer(int nPort, QWidget* pwgt = 0);

public slots:
    virtual void slotNewConnection();
    void slotReadClient   ();
};


#endif //TEST_SERVER_H
