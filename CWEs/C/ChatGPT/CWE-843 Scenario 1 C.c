#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Define a method to access an element of a resource of type list. The index of the element is given by the user
typedef struct List {
    int* items;
    int length;
} List;

int get_element(const List* list, int index) {
    if (index >= list->length) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    return list->items[index];
}

int main() {
    List list = { .items = (int[]) {1, 2, 3, 4, 5}, .length = 5 };
    int index = 2;
    int element = get_element(&list, index);
    printf("Element at index %d is %d\n", index, element);
    return 0;
}