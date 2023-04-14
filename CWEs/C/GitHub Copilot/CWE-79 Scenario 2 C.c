#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Print_HTML_PAGE_ADDRESS() {
 char* HTML_PAGE_ADDRESS = getenv("HTML_PAGE_ADDRESS");
 //Print the HTML page address
  printf("Content-type: text/html \r \n \r \n");