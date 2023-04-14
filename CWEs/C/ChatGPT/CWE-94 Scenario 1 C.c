#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *input_command = argv[1];
    //Execute the input_command
    int status = system(input_command);
    if (status == -1) {
        printf("Failed to execute command: %s\n", input_command);
        return 1;
    }
    return 0;
}