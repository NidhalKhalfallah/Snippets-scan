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

#define PORT 443

int main(int argc, char *argv[])
{
    char buf[1024];
    struct sockaddr_in server;
    struct hostent *host;
    int ret;
    SSL_CTX *ssl_ctx = NULL;
    SSL *ssl = NULL;
    BIO *out = NULL;
    BIO *in = NULL;
    BIO *ssl_bio = NULL;
    int i;
    char **pp;
    char *host_name = NULL;
    char *cert_file = NULL;
    char *key_file = NULL;
    char *ca_file = NULL;
    char *method = NULL;
    char *engine = NULL;
    char *host = NULL;
    char *port = NULL;
    char *path = NULL;
    char *query = NULL;
    char *fragment = NULL;
    