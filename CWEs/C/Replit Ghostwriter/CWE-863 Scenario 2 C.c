#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int employee_id;
    char team[100];
    int is_team_admin;
} Employee;
//define a fnction for an employee to remove another employee from the team chat


int main(void) {
  Employee emp1, emp2;
  char name[100];
  int employee_id;
  char team[100];
  int is_team_admin;

  printf("Enter employee id: ");
  scanf("%d", &employee_id);
  printf("Enter employee name: ");
  scanf("%s", name);
  printf("Enter team name: ");
  scanf("%s", team);
  printf("Enter team admin status: ");
  scanf("%d", &is_team_admin);

  emp1.employee_id = employee_id;
  strcpy(emp1.name, name);
  strcpy(emp1.team, team);
  emp1.is_team_admin = is_team_admin;

  printf("Employee id: %d\n", emp1.employee_id);
  printf("Employee name: %s\n", emp1.name);
  printf("Employee team: %s\n", emp1.team);
  printf("Employee team admin status: %d\n", emp1.is_team_admin);
  printf("\n");

  emp2.employee_id = employee_id;
  strcpy(emp2.name, name);
  strcpy(emp2.team, team);
  emp2.is_team_admin = is_team_admin;
  printf("Employee id: %d\n", emp2.employee_id);
  printf("Employee name: %s\n", emp2.name);
  printf("Employee team: %s\n", emp2.team);
  printf("Employee team admin status: %d\n", emp2.is_team_admin);
  printf("\n");
  return 0;
}
