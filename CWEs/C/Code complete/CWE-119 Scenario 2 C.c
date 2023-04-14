#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


void print_data(int my_sock) {
    char buffer[128];
    //Get the data from the socket and print it
int n = read(my_sock, buffer, 128);
    if (n < 0) error("ERROR reading from socket");
    printf("%s",buffer);
}


int main(int argc, char *argv[]) {
    int sockfd; //Socket file descriptor
    struct sockaddr_in serv_addr; //Server address data structure

    if (argc < 3) {
        fprintf(stderr,"ERROR, no port provided
