#include "serverhandler.h"
#include <QDebug>
ServerHandler::ServerHandler(int socket): socket(socket)
{

}

void ServerHandler::run()
{

    while(1){
       // array.push_back(io.recv(socket));
        bytes_read = recv(socket, buf, 1024, 0);
        if(bytes_read <= 0) break;
        send(socket, buf, bytes_read, 0);
        array.push_back(buf);
        qDebug() << array;
    }
}
