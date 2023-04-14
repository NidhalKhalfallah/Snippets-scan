#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    for (int i = 0; i < 10; i++) {
    int *factorial;
    factorial = (int *) malloc(sizeof(int));
    //calculate factorial of i
*factorial = 1;
    for (int j = i; j > 0; j--) {
        *factorial *= j;
    }

    printf("%d! is %d", i, *factorial);
    free(factorial);
}
return 0;
}
