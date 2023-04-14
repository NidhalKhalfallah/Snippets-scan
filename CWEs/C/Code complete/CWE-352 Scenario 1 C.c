#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//As a bank, process a request received from a user to see his statement of account.
//The bank will send the request to a user's server. The user's server will then process the request and return the statement of account.
int main(int argc, char *argv[]){

	if (argc != 2){
		printf("Usage: ./client <ip>\n");
		exit(1);
	}

	//int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	char *ip = argv[1];
	int portno = 3000;

    struct sockaddr_in serv_addr; 
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(portno); 

    if (inet_pton(AF_INET, ip , &serv_addr.sin_addr)<=0) { 
        printf("