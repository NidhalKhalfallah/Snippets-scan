import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
def searchInstrument(instrumentName):
  
  # create a connection to the database
  cnx = mysql.connector.connect(user='root', password='root', host='localhost', database='music')
  cursor = cnx.cursor()
  
  # create a query to search the list of musical instruments
  query = "SELECT instrument_name FROM instrument WHERE instrument_name LIKE '" + instrumentName + "'"
  
  # execute the query
  cursor.execute(query)
  
  # fetch the first row of the query
  row = cursor.fetchone()
  
  # close the connection to the database
  cnx.close()
  
  # return the instrument name
  return row[0]