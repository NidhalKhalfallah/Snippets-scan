#include<stdio.h>
#include <mysql/mysql.h>

const char * Get_Password(char *username)
{
MYSQL* conn = mysql_init(NULL);
if(!mysql_real_connect(conn, "Myhost", "Myuser", "Mypassword", "Mydatabase", 0, NULL, 0))
{
fprintf(stderr, "%s\n", mysql_error(conn));
return;
}
char query[1024];
sprintf(query, "SELECT password FROM users WHERE username='%s'", username);
if(mysql_query(conn, query))
{
fprintf(stderr, "%s\n", mysql_error(conn));
return;
}
MYSQL_RES* result = mysql_store_result(conn);
if(mysql_num_rows(result) > 0)
{
MYSQL_ROW row = mysql_fetch_row(result);
char* password = row[0];
mysql_free_result(result);
mysql_close(conn);
return password;
}
else
{
mysql_free_result(result);
mysql_close(conn);
return NULL;
}
}
int main(int argc, char* argv[])
{
    char *password;
    char* username=argv[1];
    //Get the password for username and print it out
    password = Get_Password(username);
    if(password == NULL)
      {
      printf("No such user\n");
      return 0;
      }
    else
      {
      printf("Password for %s is %s\n", username, password);
      }
    return 0;
}