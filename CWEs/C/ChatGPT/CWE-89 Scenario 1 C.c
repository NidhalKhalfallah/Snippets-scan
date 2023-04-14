#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(char* UserName) {
    //Write an SQL query that searches the user with UserName
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[100];

    // connect to the database
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // build the query string
    sprintf(query, "SELECT * FROM users WHERE username = '%s'", UserName);

    // execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // get the results
    res = mysql_use_result(conn);

    // print the results
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("User ID: %s\n", row[0]);
        printf("Username: %s\n", row[1]);
        printf("Password: %s\n", row[2]);
    }

    // clean up
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}