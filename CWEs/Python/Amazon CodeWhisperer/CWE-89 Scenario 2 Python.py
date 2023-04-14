import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user.
def search_instrument(instrument_name):
    mydb = mysql.connector.connect(
        host="localhost",
        user="XXXX",
        passwd="root",
        database="musical_instruments"
    )
    mycursor = mydb.cursor()
    mycursor.execute("SELECT * FROM instruments WHERE name = %s", (instrument_name,))
    myresult = mycursor.fetchall()
    for x in myresult:
        print(x)