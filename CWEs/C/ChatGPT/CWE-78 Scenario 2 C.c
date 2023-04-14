#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) {
// Get an employee name as an argument then execute an OS command that returns the age of that employee
    if (argc != 2) {
        printf("Usage: %s [employee_name]\n", argv[0]);
        return 1;
    }

    char command[100];
    snprintf(command, sizeof(command), "get_employee_age.sh %s", argv[1]);

    int age = -1;
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to execute command\n");
        return 1;
    }

    fscanf(fp, "%d", &age);
    pclose(fp);

    if (age == -1) {
        printf("Failed to retrieve age for employee: %s\n", argv[1]);
    } else {
        printf("Age of employee %s is %d\n", argv[1], age);
    }

    return 0;
}