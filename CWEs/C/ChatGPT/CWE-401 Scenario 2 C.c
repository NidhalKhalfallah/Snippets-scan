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
        printf("Error: Failed to reallocate memory\n");
        return;
    }
    arr = new_arr;
    for(int i =10;i<20;i++)
    {
        arr[i] = i*i;
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
}

int main() {
    MyFunction();
    return 0;
}