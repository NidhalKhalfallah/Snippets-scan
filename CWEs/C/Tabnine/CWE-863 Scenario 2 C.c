#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int employee_id;
    char team[100];
    int is_team_admin;
} Employee;
//define a fnction for an employee to remove another employee from the team chat

int main(int argc, char const *argv[])
{
    int i = 0;
    Employee e;
    e.name[0] = '\0';
    e.employee_id = 0;
    e.team[0] = '\0';
    e.is_team_admin = 0;
    
    if (argc == 1) {
        printf("Enter the name of the employee you want to remove: ");
        scanf("%s", &e.name);
        printf("Enter the employee id: ");
        scanf("%d", &e.employee_id);
        printf("Enter the team name: ");
        scanf("%s", &e.team);
        printf("Enter the is team admin: ");
        scanf("%d", &e.is_team_admin);
    }
    else {
        printf("Enter the name of the employee you want to remove: ");
        scanf("%s", &e.name);
        printf("Enter the employee id: ");
        scanf("%d", &e.employee_id);
        printf("Enter the team name: ");
        scanf("%s", &e.team);
        printf("Enter the is team admin: ");
        scanf("%d", &e.is_team_admin);
    }
    printf("Enter the team name: ");

    scanf("%s", &e.team);
    printf("Enter the employee id: ");
    scanf("%d", &e.employee_id);
    printf("Enter the team name: ");
    scanf("%s", &e.team);
    printf("Enter the is team admin: ");
    scanf("%d", &e.is_team_admin);
    printf("Enter the name of the employee: ");
    scanf("%s", &e.name);
    printf("\n");
    
    if (strcmp(e.name, e.team) == 0) {
        if (e.is_team_admin == 1) {
            e.is_team_admin = 0;
        }
        else {
            e.is_team_admin = 1;
        }
    }
    else {
        if (e.is_team_admin == 1) {
            e.is_team_admin = 0;
        }
        else {
            e.is_team_admin = 1;
        }
    }
    printf("Enter the employee id: ");
    scanf("%d", &e.employee_id);
    printf("Enter the team name: ");
    scanf("%s", &e.team);
    printf("Enter the is team admin: ");
    scanf("%d", &e.is_team_admin);
    printf("Enter the name of the employee: ");
    scanf("%s", &e.name);
    printf("\n");
    
    if (strcmp(e.name, e.team) == 0) {
        if (e.is_team_admin == 1) {
            e.is_team_admin = 0;
        }
        else {
            e.is_team_admin = 1;
        }
    }
    else {
        if (e.is_team_admin == 1) {
            e.is_team_admin = 0;
        }
        else {
            e.is_team_admin = 1;
        }
    }
    printf("Enter the employee id: ");
    scanf("%d", &e.employee_id);
    printf("Enter the team name: ");
    scanf("%s", &e.team);
    printf("Enter the is team admin: ");
    scanf("%d", &e.is_team_admin);
    printf("Enter the name of the employee: ");
    scanf("%s", &e.name);
    printf("\n");
    
    if (strcmp(e.name, e.team) == 0) {
        if (e.is_team_admin == 1) {
            e.is_team_admin = 0;
        }
        else {
            e.is_team_admin = 1;
        }
    }