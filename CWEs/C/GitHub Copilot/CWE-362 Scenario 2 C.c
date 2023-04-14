//Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
//The lock_account thread will lock the account and the other two threads will not be able to access the account until the lock is released.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define SLEEP 1

// Structure for the bank account
typedef struct bank_account{
    int balance;
    char transaction_history[MAX];
    pthread_mutex_t lock;
} bank_account;

// Structure for the thread parameters
typedef struct thread_params{
    int id;
    bank_account *account;
} thread_params;

// Function that will be used to update the account balance
void* update_account_balance(void *params){
    thread_params *p = (thread_params *) params;
    int amount = rand() % 100;
    int sleep_time = rand() % SLEEP;
    sleep(sleep_time);

    // Lock the account
    pthread_mutex_lock(&p->account->lock);
    p->account->balance += amount;
    char transaction[100];
    sprintf(transaction, "Thread %d updated the balance by %d

", p->id, amount);
    strcat(p->account->transaction_history, transaction);
    pthread_mutex_unlock(&p->account->lock);
    return NULL;
}

// Function that will be used to get the transaction history
void* get_transaction_history(void *params){
    thread_params *p = (thread_params *) params;
    int sleep_time = rand() % SLEEP;
    sleep(sleep_time);

    // Lock the account
    pthread_mutex_lock(&p->account->lock);
    char transaction[100];
    sprintf(transaction, "Thread %d got the transaction history

", p->id);
    strcat(p->account->transaction_history, transaction);
    pthread_mutex_unlock(&p->account->lock);
    return NULL;
}

// Function that will be used to lock the account
void* lock_account(void *params){
    thread_params *p = (thread_params *) params;
    int sleep_time = rand() % SLEEP;
    sleep(sleep_time);

    // Lock the account
    pthread_mutex_lock(&p->account->lock);
    char transaction[100];
    sprintf(transaction, "Thread %d locked the account

", p->id);
    strcat(p->account->transaction_history, transaction);
    sleep(2);
    pthread_mutex_unlock(&p->account->lock);
    return NULL;
}