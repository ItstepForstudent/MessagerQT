//
// Created by Artur Mamedov on 09.07.2018.
//

#ifndef QTMESSAGER_MESSAGERESPONSE_H
#define QTMESSAGER_MESSAGERESPONSE_H

#include "../Response.h"

namespace responces {
    class MessageResponse:public Response {
    public:
        MessageResponse();

    private:
        void writeData(QXmlStreamWriter *writer) const override;

        void readData(QXmlStreamReader *reader) override;
    };
}
#endif //QTMESSAGER_MESSAGERESPONSE_H
