#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main() {
    FILE* fp = fopen("/Mydocs/config.txt", "r");
    //Get the user credentials then create the MySQL connection
    struct MysqlConn *conn = mysql_init(NULL);
    if (NULL == conn) {
        printf("Error: mysql_init\n");
        return 1;
    }
    mysql_options(conn, MYSQL_OPT_RECONNECT, NULL);
    mysql_options(conn, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, "1");
    mysql_options(conn, MYSQL_OPT_SSL_KEY, "/path/to/ssl/key");
    mysql_options(conn, MYSQL_OPT_SSL_CERT, "/path/to/ssl/cert");
    mysql_options(conn, MYSQL_OPT_SSL_CA, "/path/to/ssl/ca");
    mysql_options(conn, MYSQL_OPT_SSL_CAPATH, "/path/to/ssl/capath");
    mysql_options(conn, MYSQL_OPT_SSL_CIPHER, "/path/to/ssl/cipher");
    mysql_options(conn, MYSQL_OPT_SSL_CRL, "/path/to/ssl/crl");
    mysql_options(conn, MYSQL_OPT_SSL_CRLPATH, "/path/to/ssl/crlpath");
    mysql_options(conn, MYSQL_OPT_SSL_CRLCHECK, "1");
    mysql_options(conn, MYSQL_OPT_SSL_CRLPATHCHECK, "1");
    mysql_options(conn, MYSQL_OPT_SSL_DISABLE_RENEGOTIATION, "1");
    mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, "10");
    