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
//use the GET method to request a web page
int main(int argc, char *argv[]){
	if (argc != 2) {
		printf("Usage: %s <port>\n", argv[0]);
		return 1;
	}

	int port = atoi(argv[1]);
	if (port < 1024 || port > 65535) {
		printf("<port> must be between 1024 and 65535.");
		return 1;
	}

	//initialize the SSL library and print out error message if there is one
	SSL_library_init();
	ERR_load_BIO_strings();
	ERR_load_crypto_strings();

    //create a socket for TCP connection to establish a connection with google.com 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {  //check if the socket is created successfully or not. If not, exit the program. 
        perror("socket");  //print out error message when it fails to create a socket  
        exit(EXIT_FAILURE);   //exit from this program because of failure in creating a socket  
    }

    struct sockaddr_in serverAddr;     /* structure that holds an IP address */      /* set all values in the structure to zeros */       memset(&serverAddr, '\0', sizeof(serverAddr));       serverAddr.sin_family = AF_INET;       serverAddr.sin_port = htons(port);       serverAddr.sin_addr.s_addr = INADDRESS("google-public-dns-a.google.com");       printf("Connecting...");       
if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {           perror("connect");           exit(EXIT_FAILURE);       }       printf("Connected to google.com");
//create a SSL context
    SSL_CTX *ctx = NULL;
    ctx = SSL_CTX_new(SSLv23_client_method());

	//set the socket to be used for ssl connection 
	SSL *ssl;   /* structure that holds an encrypted connection */      ssl = SSL_new(ctx);       if (!ssl) {           ERR_print_errors_fp(stderr);           exit(EXIT_FAILURE);       }       printf("Connecting...");       
if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {           perror("connect");           exit(EXIT_FAILURE);       }       printf("Connected to google.com

    //attach the socket descriptor with the ssl connection 
    if (!SSL_set_fd(ssl, sockfd)) {          ERR_print_errors();          exit(-1);      }      printf("Connecting...");       
if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {           perror("connect");           exit(-1);       }      printf("Connected to google.com

    //perform handshake on the established connection and print out error message if there is one 
    int ret = 0;   /* perform handshake */     ret = SSLizeConnection(&ssl, &ctx, "google-public-dns-a.google.com", 443 );     if (ret != 1) {         fprintf(stderr,"Error in performing handshake");
//send a GET request to google.com 
    char *request = "GET / HTTP/1.0\r
	printf("Sending request..."); 
    ret = SSL_write(ssl, request, strlen(request)); 

