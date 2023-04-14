#include <stdio.h>
//define a function that gets a value at a given index from an array
int get_value_at_index(int* array, int size, int index) {
    if (index < 0 || index >= size) {
        printf("Index out of range!\n");
        return -1;
    } else {
        return array[index];
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);

    int index1 = 2;
    int value1 = get_value_at_index(array, size, index1);
    printf("Value at index %d: %d\n", index1, value1);

    int index2 = 5;
    int value2 = get_value_at_index(array, size, index2);
    printf("Value at index %d: %d\n", index2, value2);

    return 0;
}