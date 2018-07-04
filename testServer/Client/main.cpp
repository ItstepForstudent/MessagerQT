#include <QApplication>
#include "testClient.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    testClient     client("localhost", 2323);

    client.show();

    return app.exec();
}