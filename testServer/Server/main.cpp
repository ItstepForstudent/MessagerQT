#include <QApplication>
#include <iostream>
#include"testServer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testServer server(2323);
    server.show();

    return a.exec();
}
