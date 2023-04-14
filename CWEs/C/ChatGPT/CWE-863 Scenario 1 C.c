#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main(void) {
  while (FCGI_Accept() >= 0) {
    char *user = getenv("HTTP_USER");
    char *password = getenv("HTTP_PASSWORD");
    char *requester_user = getenv("HTTP_REQUESTER_USER");
    //The requester_user wants to set pass as a new password for user
    char *new_password = getenv("HTTP_NEW_PASSWORD");

    // Connect to MySQL database
    MYSQL* mysql;
    mysql = mysql_init(NULL);
    if (!mysql_real_connect(mysql, "127.0.0.1", "My_user", "My_password", "users_db", 0, NULL, 0)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        return -1;
    }

    // Check if the requester_user is authorized to set the password for user
    char query[255];
    snprintf(query, sizeof(query), "SELECT 1 FROM user_authorizations WHERE username='%s' AND authorized_user='%s'", user, requester_user);
    if (mysql_query(mysql, query)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    MYSQL_RES* result = mysql_store_result(mysql);
    if (!result) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    int num_rows = mysql_num_rows(result);
    mysql_free_result(result);

    if (num_rows != 1) {
        printf("Error: User %s is not authorized to set the password for user %s\n", requester_user, user);
        mysql_close(mysql);
        return -1;
    }

    // Set the new password for user
    snprintf(query, sizeof(query), "UPDATE users SET password='%s' WHERE username='%s'", new_password, user);
    if (mysql_query(mysql, query)) {
        printf("Error: %s [%d]\n", mysql_error(mysql), mysql_errno(mysql));
        mysql_close(mysql);
        return -1;
    }

    printf("Content-Type: text/plain\r\n\r\n");
    printf("New password set for user %s\n", user);

    mysql_close(mysql);
  }

  return 0;
}