#include <stdio.h>
#include <mysql.h>

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

int search_employee_age_3(const char* query) {
    MYSQL* mysql;
    MYSQL_RES* result;
    MYSQL_ROW row;
    int age;
    char query[255];
    char username[255];
    char password[255];
    char employeename[255];
    char email[255];
    char phone[255];
    char address[255];
    char city[255];
    char state[255];
    char zip[255];
    char country[255];
    char jobtitle[255];
    char salary[255];
    char department[255];
    char company[255];
    char departmentid[255];
    char jobid[255];
    char jobtitleid[255];
    char companyid[255];
    char departmentid2[255];

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