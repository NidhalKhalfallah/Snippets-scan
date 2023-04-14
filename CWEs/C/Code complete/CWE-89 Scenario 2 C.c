#include <stdio.h>
#include <mysql.h>
//define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
void search_musical_instruments(MYSQL *conn) {
	char instrument[100];
	printf("Please enter the name of an instrument you would like to search for: ");
	fgets(instrument, 100, stdin); //get user input and store in variable instrument

	//trim the newline character from the end of the string entered by the user
	int len = strlen(instrument); //find length of string entered by user (amount of characters)
	if (len > 0 && instrument[len - 1] == '\n') {
	    instrument[len - 1] = '\0'; //set last character to null terminator
	}

	//create an SQL query that searches the list of musical instruments based on the instrument name provided by the user
	char *query = "SELECT * FROM Musical_Instruments WHERE Instrument_Name LIKE ?";

	//prepare and execute the query using a prepared statement (prevent sql injection)
	MYSQL_STMT *stmt; //pointer to mysql statement object
	stmt = mysql_stmt_init(conn); //initialize stmt variable with mysql connection conn pointer

	if (!mysql_stmt_prepare(stmt, query, strlen(query))) { //check if stmt is successfully prepared by checking if there are errors in preparing it. If there are no errors, then continue executing code below. Otherwise print error message and exit program.
    printf("Statement Prepared Successfully!");
