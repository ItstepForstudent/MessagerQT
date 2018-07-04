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
    const QString &getType() const;
    void setType(const QString &type);

public:
    explicit Request(const QString &type);
    static std::shared_ptr<Request> createRequest(const QString& xml);
    const QString toXML() const;
    virtual ~Request()= default;

protected:
    virtual void writeData(QXmlStreamWriter* writer) const = 0;
    virtual void readData(QXmlStreamReader* reader) = 0;

    static std::shared_ptr<Request> createInstance(QString type);
};


#endif //QTMESSAGER_REQUEST_H
