#include <stdio.h>
int main(int argc, char** argv) {
    char fileLocation[9] = "C:/Users/";
//read a file located in fileLocation directory
    FILE *fp = fopen(fileLocation, "r");
    if (fp == NULL) {
        printf("File not found");
        return 1;
    }
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}