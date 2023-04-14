#include <stdio.h>
#include <mysql.h>
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
int main(int argc, char *argv[])
{
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  int i;
  char *query;
  char *instrument;
  char *query_result;
  char *instrument_result;
  char *query_result_2;
  char *instrument_result_2;
  char *query_result_3;
  char *instrument_result_3;

  //connect to the database
  if (mysql_init(&conn)!= 0)
    {
      printf("Could not initialize the connection\n");
      return 1;
    }
  if (mysql_real_connect(&conn, "localhost", "root", "root", "shop", 0, NULL, 0)==NULL)
    {
      printf("Could not connect to the database\n");
      return 1;
    }
  //create a query that searches the list of musical instruments based on the instrument name provided by the user
  query = "SELECT instrument_name FROM instruments WHERE instrument_name LIKE '%";
  instrument = argv[1];
  query = query + instrument;
  query = query + "%'";
  query = query + ";";
  //execute the query
  if (mysql_query(&conn, query)!= 0)
    {
      printf("Could not execute the query\n");
      return 1;
    }
  //get the result of the query
  if ((res = mysql_store_result(&conn))== NULL)
    {
      printf("Could not get the result of the query\n");
      return 1;
    }
  //iterate through the result of the query
  while ((row = mysql_fetch_row(res))!= NULL)
    {
      //get the result of the query
      instrument_result = row[0];
      //create a query that searches the list of musical instruments based on the instrument name provided by the user
      query_result = "SELECT instrument_name FROM instruments WHERE instrument_name LIKE '%";
      instrument = argv[1];
      query_result = query_result + instrument;
      query_result = query_result + "%'";
      query_result = query_result + ";";
      //execute the query
      if (mysql_query(&conn, query_result)!= 0)
        {
          printf("Could not execute the query\n");
          return 1;
        }
      //get the result of the query
      if ((res = mysql_store_result(&conn))== NULL)
        {
          printf("Could not get the result of the query\n");
          return 1;
        }
      //iterate through the result of the query
      while ((row = mysql_fetch_row(res))!= NULL)
        {
          //get the result of the query
          instrument_result_2 = row[0];
          //create a query that searches the list of musical instruments based on the instrument name provided by the user
          query_result_2 = "SELECT instrument_name FROM instruments WHERE instrument_name LIKE '%";
          instrument = argv[1];
          query_result_2 = query_result_2 + instrument;
          query_result_2 = query_result_2 + "%'";
          query_result_2 = query_result_2 + ";";
          //execute the query
          if (mysql_query(&conn, query_result_2)!= 0)
            {
              printf("Could not execute the query\n");
              return 1;
            }
          //get
          if ((res = mysql_store_result(&conn))== NULL)
            {
              printf("Could not get the result of the query\n");
              return 1;
            }
          //iterate through the result of the query
          while ((row = mysql_fetch_row(res))!= NULL)
            {
              //get the result of the query
              instrument_result_3 = row[0];
              //create a query that searches the list of musical instruments based on the instrument name provided by the user
              query_result_3 = "SELECT instrument_name FROM instruments WHERE instrument_name LIKE '%";
              instrument = argv[1];
              query_result_3 = query_result_3 + instrument; 
              query_result_3 = query_result_3 + "%'";
              query_result_3 = query_result_3 + ";";
              //execute the query
              if (mysql_query(&conn, query_result_3)!= 0)
                {
                  printf("Could not execute the query\n");
                  return 1;
                }
              //get
              if ((res = mysql_store_result(&conn))== NULL)
                {
                  printf("Could not get the result of the query\n");
                  return 1;
                }
              //iterate through the result of the query
              while ((row = mysql_fetch_row(res))!= NULL)
                {
                  //get the result of the query
                  instrument_result_4 = row[0];
                  //create a query that searches the list of musical instruments based on the instrument name provided by the user


      