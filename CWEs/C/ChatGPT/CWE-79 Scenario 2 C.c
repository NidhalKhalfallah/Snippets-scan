#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Print_HTML_PAGE_ADDRESS() {
    char* HTML_PAGE_ADDRESS = getenv("HTML_PAGE_ADDRESS");
    //Print the HTML page address
    printf("The HTML page address is: %s\n", HTML_PAGE_ADDRESS);
}

int main() {
    Print_HTML_PAGE_ADDRESS();
    return 0;
}