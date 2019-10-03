#include "subscriberhandler.h"
#include <QDebug>

SubscriberHandler::SubscriberHandler(int socket, QObject *parent): socket(socket), QThread(parent)
{
    array.reserve(1024);
}

void SubscriberHandler::run()
{
    bool isStop = false;

    while(1){
        qDebug() << "array " << array;
        array.clear();
        memset(buf, 0, 1024);

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


            if(receiveXml){
                xmlRecvBytes -= bytes_read;

                if(xmlRecvBytes <= 0){
                    receiveXml = false;
                }
            } else if(array.endsWith("\r\n")){
                break;
            }

        }

        if(isStop){
            break;
        }

        QString str = array;

        if(str.contains("send xml", Qt::CaseInsensitive)){
            xmlRecvBytes = str.split(' ').at(2).toUInt();
            receiveXml = true;
            qDebug() << "recv bytes" << xmlRecvBytes;
        }
    }
}
