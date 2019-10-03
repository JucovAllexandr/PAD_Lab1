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
#include "subscriberhandler.h"

class Client: public QObject
{
    Q_OBJECT

    int socket;
    bool isConnected = false;
    sockaddr_in address;
    SubscriberHandler *subHandler;
    void send(QByteArray msg);
public:
    Client(QObject *parent = nullptr);
    void connect(QString ip, int port);
    QStringList getTopics();
    void becomeAPublisher();
    void becomeASubscriber(QString topic);
    void send(QString txt);
    ~Client();
signals:
    void becameAPublisher();
    void becameASubscriber();
    void connected();
    void connectionError();
};

#endif // CLIENT_H
