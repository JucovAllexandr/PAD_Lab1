#include "serverhandler.h"
#include <QDebug>
ServerHandler::ServerHandler(int socket): socket(socket)
{
    array.reserve(1024);
}

void ServerHandler::run()
{
    bool isStop = false;
    while(1){
        while(1){
            // array.push_back(io.recv(socket));
            bytes_read = recv(socket, buf, 1024, 0);

            if(bytes_read < 0) {
                qDebug()<<"Error recive mesg, or client "<<socket<<" disconected";
                isStop = true;
                break;
            }else if(bytes_read == 0){
                qDebug()<<"Client "<<socket<<" disconected";
                isStop = true;
                break;
            }

            array.push_back(buf);

            if(receiveJson){
                jsonBytes -= bytes_read;
                if(jsonBytes <= 0){
                    break;
                }
            }
            else if(array.endsWith("\r\n")){
                break;
            }
            qDebug() << array;
        }

        if(isStop){
            break;
        }

        qDebug() << "array";
        QString str(array);

        if(clientType == None){
            if(str.contains("publisher connect\r\n")){
                clientType = Publisher;
            }else if(str.contains("subscriber connect\r\n")){
                clientType = Subscriber;
            }
        }

        if(clientType != None){
            if(clientType == Publisher){
                if(str.contains("send json ")){
                    jsonBytes = str.split(' ').at(2).toInt();
                    receiveJson = true;
                }

            }else if(clientType == Subscriber){

            }
        }

        array.clear();
    }
    ::close(socket);
}
