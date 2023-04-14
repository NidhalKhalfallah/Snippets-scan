#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define a function to create a bank account
typedef struct BankAccount {
    char name[100];
    char account_number[50];
    double balance;
} BankAccount;

BankAccount* create_account(const char* name, const char* account_number, double balance) {
    BankAccount* account = (BankAccount*) malloc(sizeof(BankAccount));
    if (!account) {
        return NULL;
    }
    strcpy(account->name, name);
    strcpy(account->account_number, account_number);
    account->balance = balance;
    return account;
}