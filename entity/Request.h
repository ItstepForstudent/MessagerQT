//
// Created by Artur Mamedov on 03.07.2018.
//

#ifndef QTMESSAGER_REQUEST_H
#define QTMESSAGER_REQUEST_H


#include <QString>
#include <QObject>

class Request:QObject {
    Q_OBJECT
    QString type;
    virtual void parse(QXmlStreamReader*) = 0;
public:
    Request( const QString &type,QObject *parent=0);

    const QString &getType() const;

    void setType(const QString &type);

    const QString toXML() const;


    static Request* createRequest(const QString& xml,QObject *parent);


protected:
    virtual void writeData(QXmlStreamWriter* writer) const = 0;
    virtual void readData(QXmlStreamReader* reader) = 0;

    static Request *createInstance(QString qString, QObject *pObject);
};


#endif //QTMESSAGER_REQUEST_H
