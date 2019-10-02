#include "serverhandler.h"

ServerHandler::ServerHandler(int socket, QVector<QPair<QString, QStringList> > &topicTags): socket(socket), topicTags(topicTags)
{
    array.reserve(1024);
}

void ServerHandler::run()
{
    bool isStop = false;
    while(1){
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

            if(receiveJson){
                jsonBytes -= bytes_read;

                if(jsonBytes <= 0){
                    qDebug()<<"received json "<<array;
                    msg.deserializeJson(array);

                    /*add correction words*/
                    QString message = msg.message();

                    for(int i = 0; i < topicTags.size(); ++i){
                        for(int j = 0; j < topicTags.size(); ++j){
                            if(message.contains(topicTags.at(i).second.at(j), Qt::CaseInsensitive)){
                                qDebug()<<"insert into "<< topicTags.at(i);
                                query.prepare("insert into Messages (TopicName, Message) values (:TopicName, :Message)");
                                query.bindValue(":TopicName", topicTags.at(i).first);
                                query.bindValue(":Message", message);

                                if(query.exec()){
                                    for(int i = 0; i < topicSubscribers.size(); ++i){
                                        QByteArray msg = message.toStdString().c_str();
                                        QByteArray buf = "send xml ";
                                        buf.push_back(QString::number(msg.size()).toStdString().c_str());
                                        buf.push_back(" \r\n");
                                        io.send(socket, buf.data(), buf.size());

                                        QThread::msleep(100);
                                        io.send(socket, msg.data(), msg.size());
                                    }
                                }else{
                                    qDebug()<<"Error inserting message" << query.lastError().text();
                                }
                            }
                        }
                    }

                    receiveJson = false;
                    break;
                }
            }
            else if(array.endsWith("\r\n")){
                break;
            }
            //qDebug() << array;
        }

        if(isStop){
            break;
        }


        QString str(array);

        if(str.contains("get topics\r\n")){
            QByteArray buf;
            for(int i = 0; i < topicTags.size(); ++i){
                buf.push_back(topicTags.at(i).first.toStdString().c_str());
                buf.push_back("\n");
            }

            SocketIO io;
            io.send(socket, buf.data(), buf.length());

            QThread::msleep(100);

            buf.clear();
            buf.push_back("+OK\r\n");
            io.send(socket, buf.data(), buf.length());
        }
        else if(clientType == None){
            QByteArray buf;
            if(str.contains("publisher connect\r\n")){
                clientType = Publisher;
                buf.push_back("+OK publisher\r\n");
                qDebug()<<"Client "<<socket<<" connect as publisher";
            }else if(str.contains("subscriber connect")){
                QString topic = str.split(' ').at(2).trimmed();
                bool isExist = false;
                if(!topic.isEmpty()){
                    query.prepare("select TopicName from Topics where TopicName = :topic");
                    query.bindValue(":topic", topic);

                    if(query.exec()){
                        while (query.next()) {
                            if(query.value(0).toString().contains(topic, Qt::CaseInsensitive)){
                                isExist = true;
                                topicSubscribers.push_back(QPair<QString, int> (topic, socket));
                            }
                        }
                    }else{
                        qDebug()<<"Error inserting message" << query.lastError().text();
                    }
                }

                if(isExist){
                    clientType = Subscriber;
                    buf.push_back("+OK subscriber\r\n");
                    qDebug()<<"Client "<<socket<<" connect as subscriber on "+topic;
                }else{
                    buf.push_back("+NO\r\n");
                }

            }else{
                buf.push_back("+NO\r\n");
            }
            io.send(socket, buf.data(), buf.size());
        }

        if(clientType != None){
            if(clientType == Publisher){
                if(str.contains("send json ")){
                    qDebug() << str;
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
