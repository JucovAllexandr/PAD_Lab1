#ifndef CLIENT_H
#define CLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <libexplain/socket.h>
#include<arpa/inet.h>
#include <QString>
#include "../Lab1Server/socketio.h"
#include <unistd.h>

class Client
{
    int socket;
    sockaddr_in address;
public:
    Client();
    void connect(QString ip, int port);
    ~Client();
};

#endif // CLIENT_H
