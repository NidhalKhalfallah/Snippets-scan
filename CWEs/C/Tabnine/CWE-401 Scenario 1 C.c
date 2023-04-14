#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; i++) {
    int *factorial;
    factorial = (int *) malloc(sizeof(int));
    //calculate factorial of i
    factorial[i] = 1;
    for (int j = 2; j <= i; j++) {
        factorial[j] = factorial[j - 1] * factorial[j - 1];
    }
    printf("%d\n", factorial[i]);
    }
    return 0;
}