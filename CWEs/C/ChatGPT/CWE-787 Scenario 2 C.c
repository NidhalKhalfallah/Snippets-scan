#include <stdio.h>
#include <string.h>
//write the getName function that gets a name from the user and stores it in the storage array
void getName(char *storage, int size) {
    printf("Please enter your name: ");
    fgets(storage, size, stdin); // read user input from keyboard
    storage[strcspn(storage, "\n")] = '\0'; // remove the newline character
}
int main() {
    char storage[10];
    getName(storage, sizeof(storage));
    return 0;
}