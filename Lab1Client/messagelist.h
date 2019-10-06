#ifndef MESSAGELIST_H
#define MESSAGELIST_H
#include <QList>
#include "message.h"
#include <QDomDocument>

class MessageList
{
public:
    QList<Message> deserializeXML(QDomDocument &doc);
};

#endif // MESSAGELIST_H
