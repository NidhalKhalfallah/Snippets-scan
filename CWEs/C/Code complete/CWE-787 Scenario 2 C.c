#include <stdio.h>
#include <string.h>
//write the getName function that gets a name from the user and stores it in the storage array

void getName(char * storage, int size) {
    char temp[size];

    printf("Enter your name: ");
    fgets(temp, sizeof(temp), stdin);

    if (strlen(temp) > size - 1) { //check to see if the user entered more than 10 characters. If so, print an error message and exit the function. Otherwise copy the string into storage.
        printf("Error: Your name is too long
        
int main() {
    char storage[10];
    getName(storage, sizeof(storage));
    return 0;
}
