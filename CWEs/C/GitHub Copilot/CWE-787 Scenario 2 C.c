#include <stdio.h>
#include <string.h>
//write the getName function that gets a name from the user and stores it in the storage array
void getName(char storage[], int size) {
    printf("Enter your name: ");
    fgets(storage, size, stdin);
    storage[strlen(storage) - 1] = '\0';
}

int main() {
    char storage[10];
    getName(storage, sizeof(storage));
    return 0;
}