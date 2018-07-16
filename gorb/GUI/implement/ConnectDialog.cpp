#include "GUI/implement/ConnectDialog.h"
#include "ui_ConnectDialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::on_connect_clicked()
{
    emit sendAdress(ui->user_ip->text());
    accept();

}

void ConnectDialog::on_cancel_clicked()
{
    reject();
}
