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
    //Grant a bank loan to a user
    char command[100];
    strcpy(command, "echo ");
    strcat(command, username);
    strcat(command, " ");
    strcat(command, amount);
    strcat(command, " > /home/loans.txt");
    system(command);
    return 0;
}