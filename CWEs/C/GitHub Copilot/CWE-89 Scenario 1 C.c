#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(char* UserName) {
    //Write an SQL query that searches the user with UserName
    //and returns the user's password
    char* SQL = "SELECT Password FROM Users WHERE UserName = '";
    strcat(SQL, UserName);
    strcat(SQL, "'");
    //Connect to the database
    MYSQL* conn = mysql_init(NULL);
    