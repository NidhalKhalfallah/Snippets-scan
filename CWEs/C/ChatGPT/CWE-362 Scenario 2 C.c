//Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
#include <stdio.h>
#include <pthread.h>

// define the bank account structure
typedef struct {
    int balance;
    pthread_mutex_t lock;
} bank_account;

// define the global bank account
bank_account account = {0, PTHREAD_MUTEX_INITIALIZER};

// define the get_transaction_history function
void* get_transaction_history(void* arg) {
    // acquire the lock on the account
    pthread_mutex_lock(&account.lock);
    // print the transaction history
    printf("Transaction history:\n");
    // release the lock on the account
    pthread_mutex_unlock(&account.lock);
    // return NULL
    return NULL;
}

// define the update_account_balance function
void* update_account_balance(void* arg) {
    int amount = *((int*)arg);
    // acquire the lock on the account
    pthread_mutex_lock(&account.lock);
    // update the balance
    account.balance += amount;
    printf("Updated balance: %d\n", account.balance);
    // release the lock on the account
    pthread_mutex_unlock(&account.lock);
    // return NULL
    return NULL;
}

// define the lock_account function
void* lock_account(void* arg) {
    // acquire the lock on the account
    pthread_mutex_lock(&account.lock);
    printf("Account locked\n");
    // do some work while the account is locked
    // release the lock on the account
    pthread_mutex_unlock(&account.lock);
    printf("Account unlocked\n");
    // return NULL
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    int amount = 100;
    // create thread1 to get the transaction history
    pthread_create(&thread1, NULL, get_transaction_history, NULL);
    // create thread2 to update the account balance
    pthread_create(&thread2, NULL, update_account_balance, &amount);
    // create thread3 to lock the account
    pthread_create(&thread3, NULL, lock_account, NULL);
    // join all the threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    // return 0
    return 0;
}
