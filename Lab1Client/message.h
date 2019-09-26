#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

class Message
{
    QString _message;
    QJsonObject jobj;
public:
    void setMessage(QString msg);
    QString message();
    QByteArray serializeToJson();
    void deserializeJson(QByteArray json);
};

#endif // MESSAGE_H
