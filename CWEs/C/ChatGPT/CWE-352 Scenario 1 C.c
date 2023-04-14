#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mysql.h>
//As a bank, process a request received from a user to see his statement of account.
int main(int argc, char* argv[]) {
  // Connect to the database
  MYSQL* conn = mysql_init(NULL);
  if (conn == NULL) {
    fprintf(stderr, "Error initializing MySQL: %s\n", mysql_error(conn));
    exit(1);
  }
  if (mysql_real_connect(conn, "localhost", "user", "password", "bank", 0, NULL, 0) == NULL) {
    fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
    exit(1);
  }

  // Get the user ID from the command line arguments
  int user_id = atoi(argv[1]);

  // Execute a query to retrieve the account information for the user
  char query[256];
  sprintf(query, "SELECT * FROM accounts WHERE id=%d", user_id);
  if (mysql_query(conn, query)) {
    fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
    exit(1);
  }

  // Process the results of the query and generate a statement of account
  MYSQL_RES* result = mysql_use_result(conn);
  if (result == NULL) {
    fprintf(stderr, "Error getting result set: %s\n", mysql_error(conn));
    exit(1);
  }

  printf("Statement of Account\n\n");
  printf("ID\tName\t\tDate\t\tType\t\tAmount\t\tBalance\n");
  printf("--------------------------------------------------------------------\n");

  double balance = 0;
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) {
    int id = atoi(row[0]);
    char* name = row[1];
    char* date = row[3];
    char* type = row[4];
    double amount = atof(row[5]);
    balance += amount;

    printf("%d\t%s\t%s\t%s\t%.2f\t\t%.2f\n", id, name, date, type, amount, balance);
  }

  mysql_free_result(result);
  mysql_close(conn);

  return 0;
}