#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>
#include <sys/socket.h>

class Protocol
{
public:
    Protocol();
    bool send(int socket, char *buf, int len);
    QByteArray* recv(int socket);
};

#endif // PROTOCOL_H
