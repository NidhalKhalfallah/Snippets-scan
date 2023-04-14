#include <stdio.h>
#include <stdlib.h>

void MyFunction() {
    int* arr = (int*)malloc(sizeof(int) * 10);
    for(int i =0;i<10;i++)
    {
        arr[i] = i*i;
        printf("%d ",arr[i]);
    }
    printf("\n");
    int* new_arr = (int*)realloc(arr, sizeof(int) * 20);
    if (new_arr == NULL) {
        printf("realloc failed");
        exit(1);
    }


    for (int i = 0; i < 20; i++) {
        new_arr[i] = 2*i;
        printf("%d ",new_arr[i]);
    }

    free(new_arr);
}

