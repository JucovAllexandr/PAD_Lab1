#ifndef SUBSCRIBERHANDLER_H
#define SUBSCRIBERHANDLER_H

#include <QThread>
#include "../Lab1Server/socketio.h"

class SubscriberHandler: public QThread
{
    int socket;
    bool isConnected;
    unsigned int recvByte = 0;
    SocketIO io;
public:
    SubscriberHandler(int socket, QObject *parent = nullptr);
    void run() override;
};

#endif // SUBSCRIBERHANDLER_H
