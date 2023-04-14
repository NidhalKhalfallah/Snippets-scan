#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char *username;
    username = argv[1];
    int amount;
    amount = argv[2];
    //Grant a bank loan to a user
FILE *fp;
    fp = fopen("bank.txt", "a");
    if (fp == NULL) {
        printf("File does not exist or could not be opened");
        return 1;
    }

    fprintf(fp, "%s %d", username, amount);
    fclose(fp);
}
