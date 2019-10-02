#include "client.h"
#include "message.h"
#include <QThread>
void Client::send(QByteArray msg)
{
    SocketIO io;
    QByteArray request;
    request.push_back("send json ");
    request.push_back(QString::number(msg.size()).toStdString().c_str());
    request.push_back(" \r\n");
    io.send(socket, request.data(), request.size());
    QThread::msleep(100);
    io.send(socket, msg.data(), msg.size());
}

Client::Client(QObject *parent): QObject (parent)
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
        isConnected = false;
        emit connectionError();
    }else {
        isConnected = true;
        emit connected();
    }
}

QStringList Client::getTopics()
{
    QStringList retList;

    if(isConnected){
        SocketIO io;
        QByteArray buf = "get topics\r\n";
        io.send(socket, buf.data(), buf.size());
        QByteArray topics = io.recv(socket);
        QByteArray recvMsg = io.recv(socket);

        if(recvMsg.contains("+OK\r\n")){
            QString tmp = topics;
            retList = tmp.split('\n');
            retList.removeLast();
            qDebug() << topics;
        }
    }
    return retList;
}

void Client::becomeAPublisher()
{
    if(isConnected){
        SocketIO io;
        QByteArray buf = "publisher connect\r\n";
        io.send(socket, buf.data(), buf.size());
        QByteArray recvMsg = io.recv(socket);
        qDebug()<<"Check publisher connect " <<recvMsg;

        if(recvMsg.contains("+OK publisher\r\n")){
            emit becameAPublisher();
        }else{
            isConnected = false;
            emit connectionError();
        }
    }
}

void Client::becomeASubscriber(QString topic)
{
    if(isConnected){
        SocketIO io;
        QByteArray buf = "subscriber connect ";
        buf.push_back(topic.toStdString().c_str());
        buf.push_back(" \r\n");
        io.send(socket, buf.data(), buf.size());
        QByteArray recvMsg = io.recv(socket);

        qDebug()<<"Check subscriber connect " <<recvMsg;

        if(recvMsg.contains("+OK subscriber\r\n")){
            emit becameASubscriber();
        }else{
            isConnected = false;
            emit connectionError();
        }
    }
}

void Client::send(QString txt)
{
    Message msg;
    msg.setMessage(txt);
    send(msg.serializeToJson());
}

Client::~Client()
{
    ::close(socket);
}
