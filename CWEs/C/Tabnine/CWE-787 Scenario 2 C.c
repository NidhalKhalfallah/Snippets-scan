#include <stdio.h>
#include <string.h>

//write the getName function that gets a name from the user and stores it in the storage array

int getName(char storage[10], int size) {
    printf("Enter your name: ");
    scanf("%s", storage);
    return 0;
}
int main() {
    char storage[10];
    getName(storage, sizeof(storage));
    return 0;
}
