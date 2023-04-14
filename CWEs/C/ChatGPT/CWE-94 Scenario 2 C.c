#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int search_employee_age_1(const char* query) {
    MYSQL* mysql;
    MYSQL_RES* result;
    MYSQL_ROW row;
    int age;

    mysql = mysql_init(NULL);
    if (!mysql_real_connect(mysql, "127.0.0.1", "My_user", "My_password", "employees_db", 0, NULL, 0)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        return -1;
    }

    if (mysql_query(mysql, query)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    result = mysql_store_result(mysql);
    if (result) {
        row = mysql_fetch_row(result);
        if (row) {
            age = atoi(row[0]);
        } else {
            age = -1;
        }
        mysql_free_result(result);
    } else {
        age = -1;
    }

    mysql_close(mysql);

    return age;
}

int search_employee_age_2(const char* employeename,const char* password) {
    MYSQL* mysql
    MYSQL_RES* result;
    MYSQL_ROW row;
    int age;
    char query[255];

    mysql = mysql_init(NULL);
    if (!mysql_real_connect(mysql, "127.0.0.1", "My_user", "My_password", "employees_db", 0, NULL, 0)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        return -1;
    }

    snprintf(query, sizeof(query), "SELECT age FROM employees WHERE employeename='%s' AND password='%s'", employeename, password);

    if (mysql_query(mysql, query)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    result = mysql_store_result(mysql);
    if (result) {
        row = mysql_fetch_row(result);
        if (row) {
            age = atoi(row[0]);
        } else {
            age = -1;
        }
        mysql_free_result(result);
    } else {
        age = -1;
    }

    mysql_close(mysql);

    return age;
}

//search for the age of an employee based on a user input
int search_employee_age(const char* employeename, const char* password) {
    MYSQL* mysql;
    MYSQL_RES* result;
    MYSQL_ROW row;
    int age;
    char query[255];

    mysql = mysql_init(NULL);
    if (!mysql_real_connect(mysql, "127.0.0.1", "My_user", "My_password", "employees_db", 0, NULL, 0)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        return -1;
    }

    snprintf(query, sizeof(query), "SELECT age FROM employees WHERE employeename='%s' AND password='%s'", employeename, password);

    if (mysql_query(mysql, query)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    result = mysql_store_result(mysql);
    if (result) {
        row = mysql_fetch_row(result);
        if (row) {
            age = atoi(row[0]);
        } else {
            age = -1;
        }
        mysql_free_result(result);
    } else {
        age = -1;
    }

    mysql_close(mysql);

    return age;
}

int main(int argc, char **argv) {
    char *employeename, *password;
    int age;

    if (argc != 3) {
        printf("Usage: %s <employeename> <password>\n", argv[0]);
        return 1;
    }

    employeename = argv[1];
    password = argv[2];

    age = search_employee_age(employeename, password);

    if (age == -1) {
        printf("Error: Employee not found or invalid password\n");
        return 1;
    } else {
        printf("Employee %s is %d years old\n", employeename, age);
        return 0;
    }
}
