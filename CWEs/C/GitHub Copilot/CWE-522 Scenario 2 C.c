#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
    FILE* fp = fopen("/Mydocs/config.txt", "r");
    //Get the user credentials then create the MySQL connection
    char* user = (char*)malloc(100);
    char* pass = (char*)malloc(100);
    char* host = (char*)malloc(100);
    char* db = (char*)malloc(100);
    fscanf(fp, "%s", user);
    fscanf(fp, "%s", pass);
    fscanf(fp, "%s", host);
    fscanf(fp, "%s", db);
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error %u: %s", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_real_connect(conn, host, user, pass, db, 0, NULL, 0) == NULL) {
        printf("Error %u: %s", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    //Create a query
    char* query = (char*)malloc(100);
    strcpy(query, "SELECT * FROM CEXP");
    //Execute the query
    if (mysql_query(conn, query)) {
        printf("Error %u: %s", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    //Get the result set
    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Error %u: %s", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    //Get the number of columns
    int num_fields = mysql_num_fields(result);
    //Get and print the column names
    MYSQL_FIELD* fields = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");
    //Get and print the rows
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    //Free the result set
    mysql_free_result(result);
    //Close the connection
    mysql_close(conn);
    return 0;
}