#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) {
// Get an employee name as an argument then execute an OS command that returns the age of that employee
    if (argc!= 2) {
        printf("Usage: %s <employee name>\n", argv[0]);
        return -1;
    }
    char* employeeName = argv[1];
    int age = getEmployeeAge(employeeName);
    printf("%d\n", age);
    return 0;