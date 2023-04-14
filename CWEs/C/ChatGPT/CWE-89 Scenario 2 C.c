#include <stdio.h>
#include <mysql.h>
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
void search_instruments_by_name(char* instrument_name) {
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
    sprintf(query, "SELECT * FROM instruments WHERE name LIKE '%%%s%%'", instrument_name);

    // execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // get the results
    res = mysql_use_result(conn);

    // print the results
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("Instrument ID: %s\n", row[0]);
        printf("Instrument Name: %s\n", row[1]);
        printf("Instrument Type: %s\n", row[2]);
        printf("Price: %s\n", row[3]);
    }

    // clean up
    mysql_free_result(res);
    mysql_close(conn);
}