#include <stdio.h>
int main(int argc, char** argv) {
    char fileLocation[9] = "C:/Users/";
//read a file located in fileLocation directory
    FILE *fp = fopen(fileLocation, "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }
    fclose(fp);
    return 0;
}