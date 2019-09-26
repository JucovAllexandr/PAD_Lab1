#include "socketio.h"


bool SocketIO::send(int socket, char *buf, int len)
{
    int total = 0;
    int n = 0;

    while(total < len)
    {
        n = (int)::send(socket, buf+total, len-total, 0);
        if(n == -1) { break; }
        total += n;
    }

    return (n==-1 ? -1 : total);
}

QByteArray SocketIO::recv(int socket)
{
    long bytes_read = 0;
    QByteArray ret_buf;
    char buf[1024] = {0};

    while(bytes_read <= 0){
        bytes_read = ::recv(socket, buf, 1024, 0);
        ret_buf.push_back(buf);
    }

    return  ret_buf;
}
