#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


void print_data(int my_sock) {
    char buffer[128];
    //Get the data from the socket and print it
    int n = recv(my_sock, buffer, 128, 0);
    if (n > 0) {
        printf("Received %d bytes: %s\n", n, buffer);
    }
}