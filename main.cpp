#include "dialog.h"
#include <QApplication>
#include <memory>
#include "chatunit/ChatUnit.h"
#include "entity/Request.h"
#include "entity/requests/GetClientsRequest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    Request* r = new GetClientsRequest();

    std::unique_ptr<Request> req(new GetClientsRequest());
    qDebug()<<r->toXML();



    ChatUnit unit;
    return a.exec();
}
