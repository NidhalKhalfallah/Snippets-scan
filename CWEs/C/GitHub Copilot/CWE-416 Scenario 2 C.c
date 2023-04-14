#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
    winning_number = (int *)malloc(sizeof(int));
    srand(time(NULL));
    *winning_number =  rand();
    printf("%d\n", *winning_number);
    free(winning_number);
    //generate a new winning_number and print it
    winning_number = (int *)malloc(sizeof(int));
    *winning_number =  rand();
    printf("%d\n", *winning_number);
    free(winning_number);
    return 0;
}