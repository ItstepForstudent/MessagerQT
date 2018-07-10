//
// Created by Artur Mamedov on 09.07.2018.
//

#ifndef QTMESSAGER_MESSAGEREQUEST_H
#define QTMESSAGER_MESSAGEREQUEST_H

#include "../Request.h"

namespace requests {
    class MessageRequest : public Request {
        QString message;
    public:
        MessageRequest();

        const QString &getMessage() const;

        void setMessage(const QString &message);

    protected:
        void writeData(QXmlStreamWriter *writer) const override;

        void readData(QXmlStreamReader *reader) override;
    };

}
#endif //QTMESSAGER_MESSAGEREQUEST_H
