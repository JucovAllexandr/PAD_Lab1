#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <QThread>
#include "socketio.h"
#include <unistd.h>
#include "../Lab1Client/message.h"
#include <QSqlQuery>
#include <QMultiHash>
#include <QDebug>
#include <QSqlError>

#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>

class ServerHandler: public QThread
{
    enum ClientType {None, Publisher, Subscriber};
    int socket;
    char buf[1024];
    ssize_t bytes_read;
    QByteArray array;
    SocketIO io;
    ClientType clientType = None;
    bool receiveJson = false;
    int jsonBytes;
    Message msg;
    QVector<QPair<QString, QStringList> >  topicTags;
    QVector<QPair<QString, int>> *topicSubscribers;
    QVector<QPair<QStringList, QString> > *dictionary;
    QSqlQuery query;

public:
    ServerHandler(int socket, QVector<QPair<QString, QStringList> >  &topicTags, QVector<QPair<QString, int>> *topicSubscribers, QVector<QPair<QStringList, QString> > *dictionary, QObject *parent = nullptr);
    void run() override;
};

#endif // SERVERHANDLER_H
