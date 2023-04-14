import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
def search_instrument(instrument_name):
    #connect to the database
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="",
        database="music_shop"
    )
    #create a cursor object
    mycursor = mydb.cursor()
    #create an SQL query
    sql = "SELECT * FROM instruments WHERE instrument_name = %s"
    #execute the query
    mycursor.execute(sql, (instrument_name,))
    #fetch the results
    result = mycursor.fetchall()
    #return the results
    return result