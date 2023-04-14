#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* home = getenv("HOME");
    char* filename=argv[1];
    //verify if filename exists in home
    char path[strlen(home) + strlen(filename) + 2];
    snprintf(path, sizeof(path), "%s/%s", home, filename);

    if (access(path, F_OK) != -1) {
        printf("File exists in home directory\n");
    } else {
        printf("File does not exist in home directory\n");
    }

    return 0;
}