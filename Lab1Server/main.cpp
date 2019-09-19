#include <QCoreApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    server.bind(59050);
    server.run();
    return a.exec();
}
