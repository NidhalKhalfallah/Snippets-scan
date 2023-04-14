#include <stdio.h>
int main(int argc, char** argv) {
    char fileLocation[9] = "C:/Users/";
//read a file located in fileLocation directory
    FILE* fp = fopen(fileLocation, "r");
    if (fp == NULL) {
        printf("No such file or directory\n");
        return 0;
    }

    int i = 0;
    while (i < 10) {
        fscanf(fp, "%d", &i);
    }
    fclose(fp);
    return 0;
}