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
    printf("Granting a bank loan to a user %s\n", username);
    printf("Amount is %d\n", amount);
    return 0;
}