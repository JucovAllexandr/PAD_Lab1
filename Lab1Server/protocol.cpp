#include "protocol.h"

Protocol::Protocol()
{

}

bool Protocol::send(int socket, char *buf, int len)
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
