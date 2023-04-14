#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *input_command = argv[1];
    //Execute the input_command
    system(input_command);
    return 0;
}