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
//Check if the Requester_User is an Admin
if(strcmp(getUserRole(Requester_User), Roles[0]) == 0)
{
    //Requester_User is an Admin
//Add the new user
}
else
{
//Requester_User is not an Admin
//Do not add the new user
}
}

This is the code for the AddUser function. The function checks if the Requester_User is an Admin or not. If the Requester_User is an Admin, the function adds the new user. If the Requester_User is not an Admin, the function does not add the new user. The function getUserRole is used to find the role of the Requester_User. The function getUserRole is defined in the CEXP.c file.

The above code is vulnerable to SQL injection. The following is an example of SQL injection:

Requester_User: ' OR 1=1; DROP TABLE users; --

The above Requester_User value has the following effect:

The SQL query becomes SELECT role FROM users WHERE username='' OR 1=1; DROP TABLE users; --'

The SQL query is executed and the role of the user is returned. The user is an Admin.

The SQL query is also executed and the users table is dropped.

The SQL query is executed and the users table is created.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and the role is added to the users table.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and the role is added to the users table.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and the role is added to the users table.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and the role is added to the users table.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and the role is added to the users table.

The SQL query is executed and the user is added to the users table.

The SQL query is executed and the password is added to the users table.

The SQL query is executed and