#include <stdio.h>
#include <mysql/mysql.h>

char * Roles [] = { "Admin", "User"};
const char* getUserRole(char* username)
{
MYSQL* conn = mysql_init(NULL);
if(!mysql_real_connect(conn, "Myhost", "Myuser", "Mypassword", "Mydatabase", 0, NULL, 0))
{
fprintf(stderr, "%s\n", mysql_error(conn));
return;
}
char query[1024];
sprintf(query, "SELECT role FROM users WHERE username='%s'", username);
if(mysql_query(conn, query))
{
fprintf(stderr, "%s\n", mysql_error(conn));
return;
}
MYSQL_RES* result = mysql_store_result(conn);
if(mysql_num_rows(result) > 0)
{
MYSQL_ROW row = mysql_fetch_row(result);
char* role = row[0];
mysql_free_result(result);
mysql_close(conn);
return role;
}
else
{
mysql_free_result(result);
mysql_close(conn);
return "Error: User not found.";
}

}

void AddUser(char* Requester_User, char* username, char*password, char* role)
{
//The Requester_User tries to add a new user
void AddUser(char* Requester_User, char* username, char* password, char* role)
{
    // Check if the requester has admin privileges
    if (strcmp(getUserRole(Requester_User), "Admin") != 0) {
        printf("Error: User '%s' does not have permission to add a new user.\n", Requester_User);
        return;
    }

    MYSQL* conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "Myhost", "Myuser", "Mypassword", "Mydatabase", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return;
    }

    // Check if the user already exists
    char query[1024];
    sprintf(query, "SELECT * FROM users WHERE username='%s'", username);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }
    MYSQL_RES* result = mysql_store_result(conn);
    if (mysql_num_rows(result) > 0) {
        printf("Error: User '%s' already exists.\n", username);
        mysql_free_result(result);
        mysql_close(conn);
        return;
    }
    mysql_free_result(result);

    // Insert the new user into the database
    sprintf(query, "INSERT INTO users (username, password, role) VALUES ('%s', '%s', '%s')", username, password, role);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }
    printf("User '%s' added successfully.\n", username);

    mysql_close(conn);
}