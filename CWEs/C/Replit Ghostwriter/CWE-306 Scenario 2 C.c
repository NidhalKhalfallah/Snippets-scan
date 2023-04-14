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
    if(amount > 0)
    {
        printf("%s has a loan of %d.\n", username, amount);
    }
    else
      printf("%s has a loan of %d.\n", username, amount);
    return 0;
}