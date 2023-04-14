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
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buf[256];
  SSL_CTX *ctx;
  SSL *ssl;
  SSL_METHOD *meth;
  SSL_CIPHER *cipher;

  if (argc!= 2)
    {
      fprintf(stderr, "Usage: %s <port>\n", argv[0]);
      exit(1);
    }
  portno = atoi(argv[1]);

  /* Create a new SSL context. */
  ctx = SSL_CTX_new(SSLv23_client_method());
  if (ctx == NULL)
    {
      fprintf(stderr, "SSL_CTX_new error\n");
      exit(1);
    }
  /* Load the client side of the SSL context */
  meth = SSLv23_client_method();
  SSL_CTX_set_ssl_version(ctx, SSL_VERSION);
  SSL_CTX_set_options(ctx, SSL_OP_ALL);
  SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);
  SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
  SSL_CTX_set_verify_depth(ctx, 1);
  SSL_CTX_set_cipher_list(ctx, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
  SSL_CTX_set_default_verify_paths(ctx);
  /* Create a new instance of SSL */
  ssl = SSL_new(ctx);
  if (ssl == NULL)
    {
      fprintf(stderr, "SSL_new error\n");
      exit(1);
    }
  /* Create a new instance of SSL connection */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
    {
      fprintf(stderr, "socket error\n");
      exit(1);
    }
  /* Setup the connection address */
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  /* Connect to server */
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
    {
      fprintf(stderr, "connect error\n");
      exit(1);
    }
  /* Send the request */
  n = sprintf(buf, "GET / HTTP/1.0\r\n\r\n");
  if (n < 0)
    {
      fprintf(stderr, "sprintf error\n");
      exit(1);
    }
  if (SSL_write(ssl, buf, n)!= n)
    {
      fprintf(stderr, "SSL_write error\n");
      exit(1);
    }
  /* Read the response */
  n = SSL_read(ssl, buf, sizeof(buf));
  if (n < 0)
    {
      fprintf(stderr, "SSL_read error\n");
      exit(1);
    }
  /* Dump the response */
  fprintf(stderr, "Server response: %s", buf);
  /* Clean up */
  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sockfd);
  return 0;
}