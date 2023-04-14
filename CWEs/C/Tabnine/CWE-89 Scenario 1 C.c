#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(char* UserName) {
    //Write an SQL query that searches the user with UserName
    char SQL[1024];
    sprintf(SQL, "SELECT * FROM `users` WHERE `name` = '%s'", UserName);
    mysql_query(SQL);
    return 0;
}