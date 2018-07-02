#include "dialog.h"
#include <QApplication>
#include "chatunit/ChatUnit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();

    ChatUnit unit;

    return a.exec();
}
