#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int employee_id;
    char team[100];
    int is_team_admin;
} Employee;
//define a fnction for an employee to remove another employee from the team chat
void remove_employee_from_team_chat(Employee *current_employee, Employee *employee_to_remove) {
if (current_employee->is_team_admin) {
printf("%s removed from %s team chat.\n", employee_to_remove->name, employee_to_remove->team);
} else {
printf("You don't have the necessary permissions to remove an employee from the team chat.\n");
}
}