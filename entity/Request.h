//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_REQUEST_H
#define QTMESSAGER_REQUEST_H


#include <QString>
#include <QObject>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>


class Request{
    QString type;
public:
    Request(const QString &type);

    const QString &getType() const;

    void setType(const QString &type);

    const QString toXML() const;


    static Request* createRequest(const QString& xml);


protected:
    virtual void writeData(QXmlStreamWriter* writer) const = 0;
    virtual void readData(QXmlStreamReader* reader) = 0;

    static Request *createInstance(QString type);
};


#endif //QTMESSAGER_REQUEST_H
