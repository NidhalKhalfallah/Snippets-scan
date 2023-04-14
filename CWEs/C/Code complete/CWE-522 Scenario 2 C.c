#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
    FILE* fp = fopen("/Mydocs/config.txt", "r");
    //Get the user credentials then create the MySQL connection
char user[100];
    char password[100];
    fscanf(fp, "%s", user);
    fscanf(fp, "%s", password);
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", user, password, NULL, 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s", mysql_error(con));
        exit(1);
    }

    if (mysql_query(con, "DROP DATABASE IF EXISTS testdb")) {
        fprintf(stderr, "%s", mysql_error(con));
        exit(1);
    }

    if (mysql_query(con, "CREATE DATABASE testdb")) {
        fprintf(stderr, "%s", mysql_error(con));
        exit(1);
    }

    //Create the tables in testdb and insert some data into them. 
    if (mysql_query(con, "USE testdb")) {
        fprintf(stderr, "%s", mysql_error(con));
        exit(-1); //Error handling is left as an exercise for the reader. 				}

     /*   if (mysql_query(con,"CREATE TABLE Persons(PersonID int,LastName varchar(255),FirstName varchar(255))")) {
            fprintf(stderr,"%s",mysql_error(con));
            exit(-1); //Error handling is left as an exercise for the reader. 			}*/

        if (mysql_query(con, "INSERT INTO Persons VALUES('1','Jones','Mary')")) {
            fprintf(stderr, "%s", mysql_error(con));
            exit(-1); //Error handling is left as an exercise for the reader. 		}

        }

        if (mysql_query(con, "INSERT INTO Persons VALUES('2','Smith','Tim')")) {
            fprintf(stderr, "%s", mysql_error(con));
            exit(-1); //Error handling is left as an exercise for the reader. 	}

        }

    /*    if (mysql_query(&myConnection,"CREATE TABLE AddressBook (PersonID int NOT NULL AUTO_INCREMENT PRIMARY KEY , LastName varchar (255) NOT NULL , FirstName varchar (255) NOT NULL)")){   //The primary key will be auto incremented by MySQL when we create it with this command.   */

     /*       printf("Table created successfully
