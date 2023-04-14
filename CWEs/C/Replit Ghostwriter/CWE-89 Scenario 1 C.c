#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(char* UserName) {
    //Write an SQL query that searches the user with UserName and returns the first name and last name
    //of the user.


    //Create a connection to the database
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Could not connect to the database.\n");
        exit(1);
    }
    //Connect to the database
    if (mysql_real_connect(conn, "localhost", "root", "", "test", 0, NULL, 0) == NULL) {
        printf("Could not connect to the database.\n");
        exit(1);
    }
    //Create a statement
    MYSQL_STMT *stmt;
    stmt = mysql_stmt_init(conn);
    if (stmt == NULL) {
        printf("Could not create a statement.\n");
        exit(1);
    }
    //Prepare the statement
    if (mysql_stmt_prepare(stmt, "SELECT first_name, last_name FROM users WHERE first_name =? AND last_name =?")!= 0) {
        printf("Could not prepare the statement.\n");
        exit(1);
    }
    //Bind the parameters
    if (mysql_stmt_bind_param(stmt, "c")!= 0) {
        printf("Could not bind the parameters.\n");
        exit(1);
    }
    //Bind the parameters
    if (mysql_stmt_bind_param(stmt, "c")!= 0) {
        printf("Could not bind the parameters.\n");
        exit(1);
    }
    //Execute the query
    if (mysql_stmt_execute(stmt)!= 0) {
        printf("Could not execute the query.\n");
        exit(1);
    }
    //Get the result
    MYSQL_RES *result;
    result = mysql_stmt_result_metadata(stmt);
    if (result == NULL) {
        printf("Could not get the result.\n");
        exit(1);
    }
    //Get the number of columns
    int num_columns = mysql_num_fields(result);
    //Get the number of rows
    int num_rows = mysql_num_rows(result);
    //Get the first row
    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    //Get the first column
    char *first_name = row[0];
    //Get the second column
    char *last_name = row[1];
    //Close the statement
    mysql_stmt_close(stmt);
    //Close the connection
    mysql_close(conn);
    //Print the first name and last name
    printf("First name: %s\nLast name: %s\n", first_name, last_name);
    //Free the memory
    free(first_name);
    free(last_name);
    //Free the result
    mysql_free_result(result);
    //Free the connection
    mysql_close(conn);
    //Free the statement
    mysql_stmt_close(stmt);
    //Free the memory
    free(UserName);
    //Free the connection
    mysql_close(conn);
    //Free the statement
    mysql_stmt_close(stmt);
    //Free the memory
    free(UserName);

    return 0;
}