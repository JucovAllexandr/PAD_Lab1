#include <QCoreApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sockaddr_in addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3500);
    addr.sin_addr.s_addr = inet_addr("74.125.235.20");

    return a.exec();
}
