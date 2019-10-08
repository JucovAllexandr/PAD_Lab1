#include "subscriberhandler.h"
#include <QDebug>
#include "message.h"
#include "client.h"

SubscriberHandler::SubscriberHandler(int socket, QObject *parent): socket(socket), QThread(parent)
{
    this->parent = (Client*) parent;
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
            qDebug() << "push "<<array;

            if(receiveXml){
                xmlRecvBytes -= bytes_read;

                if(xmlRecvBytes <= 0){
                    QDomDocument doc;
                    doc.setContent(array);
                    Message msg;
                    msg.deserializeXML(doc);
                    qDebug() << msg.message();
                    receiveXml = false;
                    emit parent->messageRecived(msg);
                    break;

                }
            }else if(receiveAllXml){
                xmlRecvBytes -= bytes_read;

                if(xmlRecvBytes <= 0){
                    QDomDocument doc;
                    doc.setContent(array);
                    MessageList msg;
                    receiveAllXml = false;
                    emit parent->messagesRecived(msg.deserializeXML(doc));
                    break;

                }
            }else if(array.endsWith("\r\n")){
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
            qDebug() << "send xml recv bytes" << xmlRecvBytes;
        }else if(str.contains("send all xml", Qt::CaseInsensitive)){
            xmlRecvBytes = str.split(' ').at(3).toUInt();
            receiveAllXml = true;
            qDebug() << "send all xml recv bytes" << xmlRecvBytes;
        }
    }
}
