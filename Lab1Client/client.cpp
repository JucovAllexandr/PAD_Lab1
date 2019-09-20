#include "client.h"
#include <QDebug>

Client::Client()
{
    socket = ::socket(AF_INET, SOCK_STREAM, 0);

    if(socket < 0){
        qDebug()<<"Error create socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }
}

void Client::connect(QString ip, int port)
{
    address.sin_port = htons((uint16_t)port);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip.toStdString().c_str());

    if(::connect(socket, (sockaddr*)&address, sizeof (address)) < 0){
        qDebug()<<"Error connect socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }else {
        SocketIO io;
        QByteArray buf = "hello world";
        io.send(socket, buf.data(), buf.size());
    }
}

Client::~Client()
{
    ::close(socket);
}
