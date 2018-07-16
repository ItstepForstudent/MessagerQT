#ifndef TOOLSDIALOG_H
#define TOOLSDIALOG_H

#include <QDialog>
#include<QString>
namespace Ui {
class ToolsDialog;
}

class ToolsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ToolsDialog(QWidget *parent = 0);
    ~ToolsDialog();
signals:
    void sendName(QString);
private slots:


    void on_close_clicked();

    void on_save_clicked();

private:
    Ui::ToolsDialog *ui;
};

#endif // TOOLSDIALOG_H
