#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *username;
    username = argv[1];
    int amount;
    amount = atoi(argv[2]);
    //Grant a bank loan to a user
    
    printf("Granting a bank loan of %d dollars to user %s\n", amount, username);
    
    return 0;
}