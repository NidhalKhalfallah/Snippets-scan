#include <stdio.h>
int main(int argc, char** argv) {
    char fileLocation[9] = "C:/Users/";
//read a file located in fileLocation directory
FILE *fptr;
    fptr = fopen(fileLocation, "r");

    if (fptr == NULL) {
        printf("Error!"); //prints error message to screen
        exit(1); //exits the program with an error code of 1
    }

    char c;

    while ((c = getc(fptr)) != EOF) { //while loop that reads a character from file and prints it to screen until end of file is reached. 
        putchar(c);
    }

     return 0; 
}
