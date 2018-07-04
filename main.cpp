#include "dialog.h"
#include <QApplication>
#include "chatunit/ChatUnit.h"
#include "entity/Request.h"
#include "entity/requests/GetClientsRequest.h"
#include "entity/responces/GetClientsResponse.h"

void testParseXMLRequest(){
    QString xml = "<?xml version=\"1.0\"?><request><type>GetClients</type><data><name>vasia</name></data></request>";
    std::shared_ptr<Request> r = Request::createRequest(xml);
    auto p = reinterpret_cast<typename std::shared_ptr<GetClientsRequest>::element_type*>(r.get());
    qDebug()<<p->getName();
    qDebug()<<r->toXML();

}

void testParseXmlResponse(){
    GetClientsResponse response;
    response.addClient(std::shared_ptr<Client>(new Client("vasia",QHostAddress("127.0.0.1"))));
    response.addClient(std::shared_ptr<Client>(new Client("petia",QHostAddress("127.0.0.2"))));
    response.addClient(std::shared_ptr<Client>(new Client("ivan",QHostAddress("127.0.0.3"))));
    qDebug()<<response.toXML();
}


void testing(){
    testParseXmlResponse();
    // testParseXMLRequest();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

   testing();





   // ChatUnit unit;
    return a.exec();
}
