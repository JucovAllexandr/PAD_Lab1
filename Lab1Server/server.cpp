#include "server.h"
#include <QDebug>


Server::Server()
{
    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(socket < 0){
        qDebug()<<"Error create socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }
}

void Server::bind(int port)
{
    address.sin_family = AF_INET;
    address.sin_port = htons((uint16_t)port);
    address.sin_addr.s_addr = INADDR_ANY;

    if(!::bind(socket, (sockaddr*)&address, sizeof(address))){
        if(::listen(socket, 1) < 0){
            qDebug()<<"Error listen socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
        }else{
            qDebug()<<"Server started, port: "<<port;
        }
    }else{
        qDebug()<<"Error bind socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }

}

void Server::run()
{
    while(1){
        int sock = accept(socket, nullptr, nullptr);
        if(sock < 0) break;
        qDebug()<<"Client connected";
        ServerHandler *sh = new ServerHandler(sock);
        sh->run();
    }
}
