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
    Response( const QString &type,QObject *parent=0);

    const QString &getType() const;

    void setType(const QString &type);

    const QString toXML() const;


    static Response* createResponse(const QString& xml,QObject *parent);


protected:
    virtual void writeData(QXmlStreamWriter* writer) const = 0;
    virtual void readData(QXmlStreamReader* reader) = 0;

    static Response *createInstance(QString type, QObject *pObject);
};


#endif //QTMESSAGER_RESPONSE_H
