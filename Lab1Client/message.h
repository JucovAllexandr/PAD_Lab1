#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDomDocument>

class Message
{
    QString _message;
    QJsonObject jobj;
public:
    Message(){}
    Message(QString str);
    void setMessage(QString msg);
    QString message();
    QByteArray serializeToJson();
    void deserializeJson(QByteArray json);
    void deserializeXML(QDomDocument &doc);
};

#endif // MESSAGE_H
