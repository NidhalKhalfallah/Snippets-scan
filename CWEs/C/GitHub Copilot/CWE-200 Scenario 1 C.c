#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//create a socket and bind it
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = inet_addr(argv[2]);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    listen(sock, 5);
    return 0;
}