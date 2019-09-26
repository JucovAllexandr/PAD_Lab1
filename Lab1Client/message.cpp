#include "message.h"

void Message::setMessage(QString msg)
{
    _message = msg;
    jobj["message"] = msg;
}

QString Message::message()
{
    return _message;
}

QByteArray Message::serializeToJson()
{
    return QJsonDocument(jobj).toJson();
}

void Message::deserializeJson(QByteArray json)
{
    jobj = QJsonDocument::fromJson(json).object();
    _message = jobj["message"].toString();
}

