#ifndef SUBSCRIBERHANDLER_H
#define SUBSCRIBERHANDLER_H

#include <QThread>
#include <QDomDocument>
#include "../Lab1Server/socketio.h"
#include "messagelist.h"

class Client;

class SubscriberHandler: public QThread
{
    Client *parent;
    int socket;
    char buf[1024];
    ssize_t bytes_read;
    QByteArray array;
    bool receiveXml = false;
    bool receiveAllXml = false;
    unsigned int xmlRecvBytes;
    SocketIO io;
public:
    SubscriberHandler(int socket, QObject *parent = nullptr);
    void run() override;
};

#endif // SUBSCRIBERHANDLER_H
