#include <stdio.h>
#include <mysql.h>
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
void search_instrument(MYSQL *conn, char *instrument_name)
{
    char query[100];
    MYSQL_RES *res;
    MYSQL_ROW row;
    sprintf(query, "SELECT * FROM instruments WHERE instrument_name = '%s'", instrument_name);
    mysql_query(conn, query);
    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("Instrument ID: %s", row[0]);
        printf("Instrument Name: %s", row[1]);
        printf("Instrument Price: %s", row[2]);
        printf("Instrument Quantity: %s", row[3]);
    }
    mysql_free_result(res);
}