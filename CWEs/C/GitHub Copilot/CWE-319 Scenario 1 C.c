#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
//establish a connection to https://www.google.com/
int main(int argc, char *argv[])
{
    SSL_CTX *ctx;
    int server;
    struct sockaddr_in dest;
    SSL *ssl;
    char *get = "GET / HTTP/1.1\r

Host: www.google.com\r

\r

";
    char buf[1024];
    int bytes;
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    server = socket(AF_INET, SOCK_STREAM, 0);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(443);
    dest.sin_addr.s_addr = inet_addr("
    bzero(&(dest.sin_zero), 8);
    connect(server, (struct sockaddr *)&dest, sizeof(struct sockaddr));
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, server);
    SSL_connect(ssl);
    SSL_write(ssl, get, strlen(get));
    bytes = SSL_read(ssl, buf, sizeof(buf));
    buf[bytes] = 0;
    printf("Received: %s", buf);
    SSL_free(ssl);
    close(server);
    SSL_CTX_free(ctx);
    return 0;
}