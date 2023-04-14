#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


void print_data(int my_sock) {
    char buffer[128];
    //Get the data from the socket and print it
    int bytes_received = recv(my_sock, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        printf("%s", buffer);
    }
    else {
        printf("Error: %s", strerror(errno));
    }
}