#include "server.h"
#include <QDebug>


Server::Server()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+"/db.sqlite3");

    if (!db.open()) {
        qDebug() << db.lastError().text();
    }

    QSqlQuery query;
    if(query.exec("SELECT name FROM sqlite_master WHERE type = \"table\"")){
        QStringList tbl_name;
        while(query.next()){
            qDebug()<<"tables "<<query.value(0);
            tbl_name.push_back(query.value(0).toString());
        }
        if(tbl_name.isEmpty() || !(tbl_name.contains("Topics", Qt::CaseInsensitive) && tbl_name.contains("Messages", Qt::CaseInsensitive))){
           createTables();
        }

    }else{
        qDebug() << query.lastError().text();
        qDebug() << db.lastError().text();
    }

    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(socket < 0){
        qDebug()<<"Error create socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }
}

void Server::bind(int port)
{
    address.sin_family = AF_INET;
    address.sin_port = htons((uint16_t)port);
    address.sin_addr.s_addr = INADDR_ANY;

    if(!::bind(socket, (sockaddr*)&address, sizeof(address))){
        if(::listen(socket, 1) < 0){
            qDebug()<<"Error listen socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
        }else{
            qDebug()<<"Server started, port: "<<port;
        }
    }else{
        qDebug()<<"Error bind socket "<<::explain_errno_socket(errno, AF_INET, SOCK_STREAM, 0);
    }

}

void Server::run()
{
    while(1){
        int sock = accept(socket, nullptr, nullptr);
        if(sock < 0) break;
        qDebug()<<"Client connected";
        ServerHandler *sh = new ServerHandler(sock);
        sh->run();
    }
}

void Server::createTables()
{
    QSqlQuery query;
    QStringList sql = CREATE_TABLES_SQL.split(';');
    for(int i =0; i < sql.size(); i++){
        if(!query.exec(sql.at(i))){
            qDebug() << query.lastError().text();
        }
    }
}
