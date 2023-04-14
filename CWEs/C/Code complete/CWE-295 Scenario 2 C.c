#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

const char * Get_SSL_Certificate(SSL *ssl)
{
    X509 *Certificate = SSL_get_peer_certificate(ssl);
    return Certificate;
}
int main(int argc, char* argv[])
{
    //Establish an SSL connection
SSL_CTX *ctx;
    int server;
    char buf[1024];

    //Load the OpenSSL library and set up the context.  This is a standard pattern for all programs in this book.
    SSL_library_init();
     SSL_load_error_strings();

     ctx = InitServerCTX();        /* initialize SSL */

     LoadCertificates(ctx, "mycert.pem", "mykey.pem"); /* load certs */

     server = OpenListener(atoi("443"));   /* create server socket */

     while (1) {      /* listen until process killed */
       struct sockaddr client;
       int len = sizeof(client);

       printf("Waiting for clients...");
       int server = accept(server, (struct sockaddr*)&client, &len);    /* accept connection as usual */

       SSL *ssl = SSL_new(ctx);              /* get new SSL state with context */
       SSL_set_fd(ssl, server);      /* set connection socket to SSL state */

        if (SSL_accept(ssl) == -1) {      /* do SSL-protocol accept */
            ERR_print_errors_fp(stderr);
            abort();
        } else {
            printf("Connected with %s encryption", SSL_get_cipher(ssl));
            char *Certificate = Get_SSL_Certificate(ssl);
            printf("%s", Certificate);
            char *certificate_subject = X509_NAME_oneline(X509_get_subject_name(Certificate), 0, 0);
            printf("%s", certificate_subject);

        }

       SSL_free(ssl);          /* release SSL state */
     }

     close(server);         /* close server socket */
     SSL_CTX_free(ctx);         /* release context */

    return 0;
}
