#ifndef SERVER_H
#define SERVER_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <libexplain/socket.h>
#include <QThread>
#include "serverhandler.h"

class Server: public QThread
{
    Q_OBJECT
    int socket;
    sockaddr_in address;
public:
    Server();
    void bind(int port);
    void run() override;
};

#endif // SERVER_H
