#include "dialog.h"
#include <QApplication>
#include "chatunit/ChatUnit.h"
#include "entity/Request.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    Request r(0,"pupkin","<x>vasia</x>");
    qDebug()<<r.toXML();

    ChatUnit unit;
    return a.exec();
}
