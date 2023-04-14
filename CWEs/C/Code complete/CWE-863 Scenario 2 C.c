#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int employee_id;
    char team[100];
    int is_team_admin;
} Employee;
//define a fnction for an employee to remove another employee from the team chat
void remove_from_team(Employee *employee, Employee *other) {
    //if the employee is not a team admin don't do anything
    if (employee->is_team_admin == 0) {
        printf("You are not an admin of this team");
    } else {
        //remove the other employee from the team chat
        strcpy(other->team, "");
    }
}
