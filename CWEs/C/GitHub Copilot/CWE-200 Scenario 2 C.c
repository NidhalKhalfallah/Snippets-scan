#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* home = getenv("HOME");
    char* filename=argv[1];
    //verify if filename exists in home
    char* fullpath = malloc(strlen(home) + strlen(filename) + 2);
    sprintf(fullpath, "%s/%s", home, filename);
    printf("fullpath: %s", fullpath);
    return 0;
}