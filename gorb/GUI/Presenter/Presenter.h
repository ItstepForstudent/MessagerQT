#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include<QList>
#include "chatunit/ChatUnit.h"
#include "GUI/implement/MainWindow.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(QObject *parent = nullptr);
    void show();
signals:

public slots:
  void connectToUser(QString);
  void upDateClientList();
  void sendNameToUnit(QString);
  void sendMassageToClient(std::shared_ptr<Client>,QString);
private:
    ChatUnit *unit;
    MainWindow *win;

};

#endif // PRESENTER_H
