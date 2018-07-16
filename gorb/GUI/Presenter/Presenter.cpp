#include "GUI/Presenter/Presenter.h"
#include<QDebug>
#include "entity/Client.h"
Presenter::Presenter(QObject *parent) : QObject(parent)
{
  unit = new ChatUnit(this);
  win = new MainWindow();
  connect(win,SIGNAL(sendAdress(QString)),this,SLOT(connectToUser(QString)));
  connect(unit,SIGNAL(onLoadingClientList()),
          this,SLOT(upDateClientList()));
 // connect(unit,SIGNAL(newClient()),this,SLOT(upDateClientList()));
  connect(win,SIGNAL(sendName(QString)),this,SLOT(sendNameToUnit(QString)));
  //connect(unit,SIGNAL(newMessage()),win,SLOT(newMessage()));

}


void Presenter::sendNameToUnit(QString name)
{
    //qDebug()<<"hi";
   unit->setCurrentClientName(name);

}

void Presenter::sendMassageToClient(std::shared_ptr<Client> client,QString msg)
{
    unit->sendMessage(client,msg);
}
void Presenter::upDateClientList(){
      win->setClientList(unit->getClientsList());
    qDebug()<<"here update";
     qDebug()<<"size unit"<<(unit->getClientsList()).size()<<" __ "<<(unit->getClientsList()).isEmpty();
     win->upDateUserPanel();
}

void Presenter::connectToUser(QString adress){
        qDebug()<<adress;
   unit->connectToAddress(adress);
}

void Presenter::show()
{
    win->show();
}
