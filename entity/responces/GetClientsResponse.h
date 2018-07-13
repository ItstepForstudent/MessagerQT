//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_GETCLIENTSRESPONSE_H
#define QTMESSAGER_GETCLIENTSRESPONSE_H


#include "../Response.h"
#include "../Client.h"
#include <memory>
namespace responces {
    class GetClientsResponse : public Response {
        QList<std::shared_ptr<Client>> clients;
    public:
        void addClient(std::shared_ptr<Client> client);

        const QList<std::shared_ptr<Client>> &getClients() const;

        void setClients(const QList<std::shared_ptr<Client>> &clients);

        GetClientsResponse();

    protected:
        void readData(QXmlStreamReader *reader) override;

        void writeData(QXmlStreamWriter *writer) const override;

    };

}
#endif //QTMESSAGER_GETCLIENTSRESPONSE_H
