//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSRESPONSE_H
#define QTMESSAGER_GETCLIENTSRESPONSE_H


#include "../Response.h"
#include "../Client.h"

namespace responces {
    class GetClientsResponse : public Response {
        QList<std::shared_ptr<Client>> clients;
    public:
        void addClient(std::shared_ptr<Client> client);

        GetClientsResponse();

    protected:
        void readData(QXmlStreamReader *reader) override;

        void writeData(QXmlStreamWriter *writer) const override;

    };

}
#endif //QTMESSAGER_GETCLIENTSRESPONSE_H
