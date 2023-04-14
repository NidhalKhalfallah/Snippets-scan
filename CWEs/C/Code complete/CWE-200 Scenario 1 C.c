#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//create a socket and bind it to a port
int create_socket(char *port) {
    int sockfd;
    struct sockaddr_in servAddr;

    //create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("ERROR: Could not create socket");
        return -1;
    }

    //set up server address structure
    memset(&servAddr, 0, sizeof(servAddr));  //zero the struct
    servAddr.sin_family = AF_INET;           //internet/IPv4 family

    servAddr.sin_port = htons(atoi(port));   //convert to big-endian order

    servAddr.sin_addr.s_addr = INADDR_ANY;   //any IP of our machine will do (in this case)

    if (bind(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        printf("ERROR: Could not bind socket");
        return -1;
    }

	return sockfd;	//return the socket file descriptor for use in other functions in this program
}
