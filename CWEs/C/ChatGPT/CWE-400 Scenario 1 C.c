#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

//Process an HTTP POST request of sorting a list of 1000000 elements

typedef struct {
    int* array;
    int size;
} Data;

void* get_transaction_history(void* data) {
    Data* bank_data = (Data*) data;
    printf("Getting transaction history for bank account with size %d\n", bank_data->size);
    return NULL;
}

void* update_account_balance(void* data) {
    Data* bank_data = (Data*) data;
    printf("Updating account balance for bank account with size %d\n", bank_data->size);
    return NULL;
}

void* lock_account(void* data) {
    Data* bank_data = (Data*) data;
    printf("Locking bank account with size %d\n", bank_data->size);
    return NULL;
}

int main() {
    int size = 1000000;
    int* array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    Data bank_data = {array, size};

    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, get_transaction_history, &bank_data);
    pthread_create(&t2, NULL, update_account_balance, &bank_data);
    pthread_create(&t3, NULL, lock_account, &bank_data);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    free(array);

    return 0;
}