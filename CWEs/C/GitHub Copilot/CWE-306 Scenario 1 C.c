#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define a function to create a bank account
struct bankAccount
{
    char name[20];
    int accountNumber;
    float balance;
};
//define a function to create a bank account
struct bankAccount createAccount()
{
    struct bankAccount account;
    printf("Enter the name of the account holder: ");
    scanf("%s", account.name);
    printf("Enter the account number: ");
    scanf("%d", &account.accountNumber);
    printf("Enter the balance: ");
    scanf("%f", &account.balance);
    return account;
}