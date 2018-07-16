#include "GUI/implement/MainWindow.h"
#include "ui_MainWindow.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow),currentClient(-1)
{
    ui->setupUi(this);
    connectDialog = new ConnectDialog(this);
    tools = new ToolsDialog(this);
    QObject::connect(connectDialog,SIGNAL(sendAdress(QString)),
                     this, SIGNAL(sendAdress(QString)));
   QObject::connect(ui->users_table,SIGNAL(currentRowChanged(int)),this,SLOT(changeChat(int)));
   QObject::connect(tools, SIGNAL(sendName(QString)),this,SIGNAL(sendName(QString)));
}

void MainWindow::changeChat(int clientIndex){
    if(currentClient == clientIndex)return;
    ui->label->setText("\t\t"+clientList[clientIndex]->getName());
    currentClient=clientIndex;
    ui->message_table->clear();
}

 void MainWindow::setClientList( QList<std::shared_ptr<Client>>&clients){
   if(clientList.isEmpty())
   {
     clientList = clients;
   } else{

       for(qint16 i(0); i<clients.size();i++)
       {    for(qint16 j(0); i<clientList.size();i++)
                    if(clients[i]->getAddress() == clientList[j]->getAddress())
                        continue;
                      else
                        clientList.push_back(clients[i]);

       }
   }
}

void MainWindow::newMessage()
{
    ui->message_table->append("new message");
}
 void MainWindow::upDateUserPanel(){
    ui->users_table->clear();
    ui->users_table->setIconSize(QSize(48,48));
     for(qint16 i=0; i<clientList.size(); i++)
     {
         ui->users_table->addItem(clientList[i]->getName()+
                                  "\n"+(clientList[i]->getAddress().toString()));
         ui->users_table->item(i)->setIcon(QPixmap("/home/user/Загрузки/Clon/MessagerQT-mamedov/GUI/img/NoAvatar.png"));
     }
        currentClient =-1;
 }


 MainWindow::~MainWindow()
{   delete connectDialog;
    delete ui;
}

void MainWindow::on_connect_clicked()
{
    if(connectDialog->exec() == QDialog::Rejected)return;
}

void MainWindow::on_Tools_clicked()
{
    if(tools->exec()== QDialog::Rejected)return;
}

void MainWindow::on_send_clicked()
{
    if(currentClient == -1)return;
    emit sendMessage(clientList[currentClient],ui->massage->text());
    ui->message_table->append(ui->massage->text());
    ui->massage->setText("");
}
