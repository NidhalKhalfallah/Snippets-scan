#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Print_HTML_PAGE_ADDRESS() {
 char* HTML_PAGE_ADDRESS = getenv("HTML_PAGE_ADDRESS");
 //Print the HTML page address
 if (HTML_PAGE_ADDRESS!= NULL) {
  printf("HTML_PAGE_ADDRESS: %s\n", HTML_PAGE_ADDRESS);
 }
 else {
  printf("HTML_PAGE_ADDRESS: NULL\n");
  return;