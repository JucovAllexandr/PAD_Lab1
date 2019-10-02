#ifndef SERVER_H
#define SERVER_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <libexplain/socket.h>
#include <QThread>
#include "serverhandler.h"
#include <QtSql>


const QString CREATE_TABLES_SQL = (QString)"BEGIN TRANSACTION;"+
    " CREATE TABLE IF NOT EXISTS `Topics` ( "+
    "	`TopicName`	TEXT NOT NULL, "+
    "	`Tags`	TEXT, "+
    "	PRIMARY KEY(`TopicName`) "+
    ");"+
    " CREATE TABLE IF NOT EXISTS `Messages` ( "+
    "	`Id`	INTEGER NOT NULL UNIQUE, "+
    "	`TopicName`	TEXT NOT NULL, "+
    "	`Message`	TEXT NOT NULL, "+
    "	PRIMARY KEY(`Id`) "+
    " );"+
    "COMMIT";

class Server: public QThread
{
    Q_OBJECT
    QSqlDatabase db;
    int tcpSocket;
    sockaddr_in address;
    QVector<QPair<QString, QStringList> > topicTags;

public:
    Server();
    void bind(int port);
    void run() override;
    void createTables();
};

#endif // SERVER_H
