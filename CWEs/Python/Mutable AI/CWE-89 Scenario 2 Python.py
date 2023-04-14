import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
def search_musical_instruments():
    #connect to the database
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        passwd="",
        database="musical_instruments"
    )
    #create a cursor object to execute SQL queries against the database
    mycursor = mydb.cursor()
    #prompt the user to enter the name of the instrument they are looking for and store it in a variable called instrument_name
    instrument_name = input("Enter the name of the instrument you are looking for: ")
    #create an SQL query that searches the list of musical instruments based on the instrument name provided by the user and store it in a variable called sql_query 
    sql_query = "SELECT * FROM musical_instruments WHERE name = '%s'" % instrument_name 
    #execute the SQL query against the database and store the result in a variable called my result 
    mycursor.execute(sql_query)
    myresult = mycursor.fetchall()
    #print the result of the SQL query against the database 
    print(myresult) 
    #close the connection to the database 
    mydb.close() 
#call the function to search for a musical instrument