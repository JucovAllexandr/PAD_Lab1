#ifndef SUBSCRIBERHANDLER_H
#define SUBSCRIBERHANDLER_H

#include <QThread>
#include "../Lab1Server/socketio.h"

class SubscriberHandler: public QThread
{
    int socket;
    char buf[1024];
    ssize_t bytes_read;
    QByteArray array;
    bool receiveXml = false;
    unsigned int xmlRecvBytes;
    SocketIO io;
public:
    SubscriberHandler(int socket, QObject *parent = nullptr);
    void run() override;
};

#endif // SUBSCRIBERHANDLER_H
