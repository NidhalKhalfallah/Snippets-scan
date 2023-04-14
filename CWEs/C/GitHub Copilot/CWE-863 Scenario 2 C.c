#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int employee_id;
    char team[100];
    int is_team_admin;
} Employee;
//define a fnction for an employee to remove another employee from the team chat
void remove_employee(Employee *employee, Employee *employee_to_remove) {
    if (employee->is_team_admin == 1) {
        strcpy(employee_to_remove->team, "");
    }
}