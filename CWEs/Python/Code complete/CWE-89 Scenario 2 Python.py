import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
def search_musical_instruments(instrument):

    #connect to the database
    conn = mysql.connector.connect(host='localhost', user='root', password='password', database='MusicalInstruments')
    
    #create a cursor object using the connection above and execute an SQL query that searches for all musical instruments with a name containing the instrument name provided by the user 
    mycursor = conn.cursor()
    sql_query = "SELECT * FROM MusicalInstruments WHERE Name LIKE '%" + instrument + "%'"

    mycursor.execute(sql_query)

    result = mycursor.fetchall()

    print(result)

    #close the connection to the database
    conn.close()
    
#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the manufacturer name provided by the user 
def search_musical_instruments_by_manufacturer(manufacturer):

    #connect to the database
    conn = mysql.connector.connect(host='localhost', user='root', password='password', database='MusicalInstruments')

    #create a cursor object using the connection above and execute an SQL query that searches for all musical instruments with a manufacturer containing the manufacturer name provided by the user 
    mycursor = conn.cursor()
    sql_query = "SELECT * FROM MusicalInstruments WHERE Manufacturer LIKE '%" + manufacturer + "%'"

    mycursor.execute(sql_query)

    result = mycursor.fetchall()

    print(result)

    #close the connection to the database
    conn.close()

