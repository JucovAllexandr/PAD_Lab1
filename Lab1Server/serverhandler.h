#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QThread>

class ServerHandler: public QThread
{
public:
    ServerHandler();
    void run() override;
};

#endif // SERVERHANDLER_H
