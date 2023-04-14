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
int main() {
    int sockfd, port = 443;
    struct sockaddr_in servaddr;
    SSL_CTX *ctx;
    SSL *ssl;

    char* hostname = "www.google.com";
    char* message = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    char buffer[4096];

    // create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // set server details
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    // create an SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());

    // create an SSL session and attach it to the socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // initiate the SSL handshake
    SSL_connect(ssl);

    // verify the SSL certificate
    if (SSL_get_verify_result(ssl) != X509_V_OK) {
        printf("Certificate verification error.\n");
        return -1;
    }

    // send an HTTP GET request to the server to retrieve the homepage
    SSL_write(ssl, message, strlen(message));

    // read the HTTP response from the server
    SSL_read(ssl, buffer, sizeof(buffer));

    printf("%s", buffer);

    // close the SSL session and TCP socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}