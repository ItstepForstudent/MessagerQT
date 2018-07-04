//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_RESPONSE_H
#define QTMESSAGER_RESPONSE_H


#include <QObject>
#include <QXmlStreamWriter>

class Response: QObject {
    QString type;
public:
    Response( const QString &type);

    const QString &getType() const;

    void setType(const QString &type);

    const QString toXML() const;


    static std::shared_ptr<Response> createResponse(const QString& xml);

    virtual ~Response()= default;

protected:
    virtual void writeData(QXmlStreamWriter* writer) const = 0;
    virtual void readData(QXmlStreamReader* reader) = 0;

    static std::shared_ptr<Response> createInstance(QString type);
};


#endif //QTMESSAGER_RESPONSE_H
