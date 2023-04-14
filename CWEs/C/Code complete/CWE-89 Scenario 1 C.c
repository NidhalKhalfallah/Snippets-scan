#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(char* UserName) {
    //Write an SQL query that searches the user with UserName.
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

     char* server = "localhost";
     char* user = "root";  //change this to your username
     char* password = "password"; //put your password (as a string) here
     char* database = "project1db";

	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server,
                            user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s", mysql_error(conn));
        exit(1);
    }

	/* send SQL query */
	if (mysql_query(conn, "SELECT * FROM user WHERE UserName = '"UserName"' LIMIT 1")) {
        fprintf(stderr, "%s", mysql_error(conn));
        exit(1);
    }

	res = mysql_use_result(conn);

	/* output table name */
	printf("