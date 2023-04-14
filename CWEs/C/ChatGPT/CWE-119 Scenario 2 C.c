#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


void print_data(int my_sock) {
    char buffer[128];
    //Get the data from the socket and print it
    ssize_t bytes_received = recv(my_sock, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving data from socket\n");
        return;
    }
    buffer[bytes_received] = '\0';
    printf("Received data: %s\n", buffer);