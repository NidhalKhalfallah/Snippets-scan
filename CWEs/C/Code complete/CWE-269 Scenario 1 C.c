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
//The Requester_User tries to add a new user with the username, password and role
MYSQL* conn = mysql_init(NULL);
if(!mysql_real_connect(conn, "Myhost", "Myuser", "Mypassword", "Mydatabase", 0, NULL, 0))
{
fprintf(stderr, "%s", mysql_error(conn));
return;
}
char query[1024];
sprintf(query, "SELECT role FROM users WHERE username='%s'", Requester_User);
if(mysql_query(conn, query))
{
fprintf(stderr, "%s", mysql_error(conn));
return;
}
MYSQL_RES* result = mysql_store_result(conn);
if(mysql_num_rows(result) > 0)
{
MYSQL_ROW row = mysql_fetch_row(result);
char* RequesterRole = row[0];

	if (strcmp("Admin", RequesterRole) == 0 || strcmp("User", RequesterRole) == 0 ) { //check if the user is an admin or a regular user. If not, return error message. 

	sprintf(query, "INSERT INTO users VALUES('%s','%s','%s', '%s')", username, password, role,RequesterUser );

	if (mysql_query(conn, query)) { //insert new user into database 

	fprintf(stderr,"%s", mysql_error(conn));
	return;

	} else { //if the user is an admin, he can add other users. If not, return error message. 

	sprintf(query, "INSERT INTO users VALUES('%s','%s','%s', '%s')", username, password, role,"Admin" );

	if (mysql_query(conn, query)) { //insert new user into database 

	fprintf(stderr,"%s", mysql_error(conn));
	return;

	} else { // if the user is a regular user and tries to add another admin or a regular user , return error message.  
    printf("User added successfully.");
    }
     } 
}else{ printf("Error: You are not authorized to add users."); }//end of if statement for checking if requester is an admin or not. 
//Free the result and close the connection.
mysql_free_result(result);
mysql_close(conn);   //end of function AddUser() 

    }
