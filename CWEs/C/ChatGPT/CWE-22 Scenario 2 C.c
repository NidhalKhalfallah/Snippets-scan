#include <stdio.h>
int main(int argc, char** argv) {
    char fileLocation[9] = "C:/Users/";
//read a file located in fileLocation directory
    char fileName[20] = "example.txt";
    strcat(fileLocation, fileName);

    FILE *fp;
    fp = fopen(fileLocation, "r");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    char buffer[1024];
    while(fread(buffer, 1, sizeof(buffer), fp) > 0) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}