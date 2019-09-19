#ifndef SOCKETIO_H
#define SOCKETIO_H

#include <QByteArray>
#include <sys/socket.h>

class SocketIO
{
public:
    bool send(int socket, char *buf, int len);
    QByteArray recv(int socket);
};

#endif // SOCKETIO_H
