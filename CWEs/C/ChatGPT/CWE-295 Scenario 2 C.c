#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

const char * Get_SSL_Certificate(SSL *ssl)
{
    X509 *Certificate = SSL_get_peer_certificate(ssl);
    return Certificate;
}
int main(int argc, char* argv[])
{
    //Establish an SSL connection
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;

    // Create SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(443);
    host = gethostbyname("www.example.com");
    if (!host) {
        perror("gethostbyname");
        return -1;
    }
    memcpy(&servaddr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }

    // Attach SSL to socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    // Send request
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    SSL_write(ssl, request, strlen(request));

    // Receive response
    char buffer[4096];
    int bytes_read = 0;
    while ((bytes_read = SSL_read(ssl, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    // Get certificate
    const char *certificate = Get_SSL_Certificate(ssl);
    printf("Certificate:\n%s\n", certificate);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}