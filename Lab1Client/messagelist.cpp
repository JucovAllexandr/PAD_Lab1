#include "messagelist.h"

QList<Message> MessageList::deserializeXML(QDomDocument &doc)
{
    QList<Message> retList;

    QDomNodeList nodeList = doc.elementsByTagName("Message");

    retList.reserve(nodeList.size());

    for(int i = 0; i < nodeList.size(); ++i){
        retList.push_back(Message(nodeList.at(i).toElement().text()));
    }

    return retList;
}
