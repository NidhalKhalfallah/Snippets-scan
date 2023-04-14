#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
    FILE* fp = fopen("/Mydocs/config.txt", "r");
    //Get the user credentials then create the MySQL connection
    if (fp == NULL) {
        printf("Error: could not open config file\n");
        return 1;
    }
    
    char db_host[100], db_user[100], db_pass[100], db_name[100];
    fscanf(fp, "%s %s %s %s", db_host, db_user, db_pass, db_name);
    fclose(fp);

    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error: could not initialize MySQL connection\n");
        return 1;
    }

    if (!mysql_real_connect(conn, db_host, db_user, db_pass, db_name, 0, NULL, 0)) {
        printf("Error: could not connect to MySQL database\n");
        mysql_close(conn);
        return 1;
    }

    // use the connection to query or modify the database

    mysql_close(conn);
    return 0;
}