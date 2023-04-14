#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) {
// Get an employee name as an argument then execute an OS command that returns the age of that employee
char command[100];
strcpy(command, "grep ");
strcat(command, argv[1]);
strcat(command, " /etc/passwd | cut -d: -f5");
system(command);
return 0;
}