#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Define a method to access an element of a resource of type list. The index of the element is given by the user
int accessElement(int *list, int index){
    return list[index];
}
int main(){
    int *list = (int *)malloc(10*sizeof(int));
    int i;
    for(i=0;i<10;i++){
        list[i] = i;
    }
    int index = 0;
    printf("Enter the index of the element you want to access: ");
    scanf("%d", &index);
    int element = accessElement(list, index);
    printf("The element at index %d is %d", index, element);
    return 0;
}