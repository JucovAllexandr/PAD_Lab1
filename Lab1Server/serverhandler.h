#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <QThread>
#include "socketio.h"
#include <unistd.h>

class ServerHandler: public QThread
{
    int socket;
    char buf[1024];
    int bytes_read;
    QByteArray array;
    SocketIO io;

public:
    ServerHandler(int socket);
    void run() override;
};

#endif // SERVERHANDLER_H
