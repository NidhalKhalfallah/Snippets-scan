#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
    FILE* fp = fopen("/Mydocs/config.txt", "r");
    //Get the user credentials then create the MySQL connection
    MYSQL *mysql = mysql_init(NULL);
    if (!mysql) {
        printf("Error: %s\n", mysql_error(mysql));
        exit(1);
    }
    //Connect to the database
    if (!mysql_real_connect(mysql, "localhost", "root", "", "", 0, NULL, 0)) {
        printf("Error: %s\n", mysql_error(mysql));
        exit(1);
    }
    //Get the database name
    char *dbname = (char*)malloc(sizeof(char) * 100);
    fscanf(fp, "%s", dbname);
    //Get the table name
    char *tablename = (char*)malloc(sizeof(char) * 100);
    fscanf(fp, "%s", tablename);
    //Get the column names
    char *colnames = (char*)malloc(sizeof(char) * 100);
    fscanf(fp, "%s", colnames);
