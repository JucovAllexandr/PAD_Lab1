#ifndef CLIENT_H
#define CLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <libexplain/socket.h>
#include<arpa/inet.h>
#include <QString>
#include "../Lab1Server/socketio.h"
#include <unistd.h>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

class Client: public QObject
{
    Q_OBJECT

    int socket;
    sockaddr_in address;
    void send(QByteArray msg);
public:
    Client(QObject *parent = nullptr);
    void connectAsPublisher(QString ip, int port);
    void connectAsSubscriber(QString ip, int port, QString topic);
    void send(QString txt);
    ~Client();
signals:
    void connectedAsPublisher();
    void connectedAsSubscriber();
};

#endif // CLIENT_H
