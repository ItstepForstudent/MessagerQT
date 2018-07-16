#include "GUI/implement/ToolsDialog.h"
#include "ui_ToolsDialog.h"

ToolsDialog::ToolsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolsDialog)
{
    ui->setupUi(this);
}

ToolsDialog::~ToolsDialog()
{
    delete ui;
}


void ToolsDialog::on_close_clicked()
{
    reject();
}

void ToolsDialog::on_save_clicked()
{
    emit sendName(ui->name->text());
    accept();
}
