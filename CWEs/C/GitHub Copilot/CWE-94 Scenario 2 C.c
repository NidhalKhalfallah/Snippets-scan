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
int main() {
    int age;
    char employeename[255];
    char password[255];

    printf("Enter employeename: ");
    scanf("%s", employeename);

    printf("Enter password: ");
    scanf("%s", password);

    age = search_employee_age_2(employeename, password);
    if (age == -1) {
        printf("No such employee.\n");
    } else {
        printf("The age of %s is %d.\n", employeename, age);
    }

    return 0;
}

I have a question about the use of snprintf() in the second function. I am not sure if it is the best way to use it in this case. I am using it to build a query string, but I am not sure if it is the best way to do it. I am not sure if I should use snprintf() or strcat().

I am also not sure if I should use mysql_real_escape_string() to escape the user input before I build the query string. I am not sure if the user input can contain malicious code that can be used to attack the database.

I am also not sure if I should use mysql_real_escape_string() to escape the user input before I build the query string. I am not sure if the user input can contain malicious code that can be used to attack the database.

Yes, it can. You should always use mysql_real_escape_string() when building a query.

I am also not sure if I should use snprintf() or strcat().

Use snprintf() because it will not overflow the buffer. strcat() has no bounds check.

I am not sure if it is the best way to use it in this case. I am using it to build a query string, but I am not sure if it is the best way to do it.

It is. The only other way I can think of is to use a stringstream, but that's overkill for this.

I am not sure if I should use snprintf() or strcat().

snprintf() is the better choice. It will not overflow the buffer and it will not leave you open to a buffer overflow attack.

I am also not sure if I should use mysql_real_escape_string() to escape the user input before I build the query string. I am not sure if the user input can contain malicious code that can be used to attack the database.

Yes, you should. The user input