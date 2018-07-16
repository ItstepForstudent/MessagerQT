#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "GUI/implement/ConnectDialog.h"
#include "GUI/implement/ToolsDialog.h"
#include "entity/Client.h"
#include<memory>
#include<QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setClientList( QList<std::shared_ptr<Client>>&);
    void upDateUserPanel();
    ~MainWindow();
signals:
   void sendAdress(QString);
   void sendName(QString);
   void sendMessage(std::shared_ptr<Client>,QString);
public slots:
   void newMessage();
private slots:
    void on_connect_clicked();
    void changeChat(int);

    void on_Tools_clicked();

    void on_send_clicked();

private:
    ConnectDialog *connectDialog;
    ToolsDialog *tools;
     Ui::MainWindow *ui;
     int currentClient;
     QList<std::shared_ptr<Client>> clientList;
};

#endif // MAINWINDOW_H
