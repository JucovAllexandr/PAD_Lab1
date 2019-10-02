#include "subscriberhandler.h"

SubscriberHandler::SubscriberHandler(int socket, QObject *parent): socket(socket), QThread(parent)
{

}

void SubscriberHandler::run()
{
    while(isConnected){
        QByteArray recvbuf = io.recv(socket);

        QString str = recvbuf;

        if(str.contains("send xml", Qt::CaseInsensitive)){

        }
    }
}
