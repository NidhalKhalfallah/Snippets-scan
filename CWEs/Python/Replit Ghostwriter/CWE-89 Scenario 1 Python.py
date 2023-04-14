import mysql.connector

def main(UserName):
   #Write an SQL query that searches the user with UserName

  # Connect to the database
  cnx = mysql.connector.connect(user='root', password='root', host='localhost', database='test')
  cursor = cnx.cursor()
  
  # Execute the query
  cursor.execute("SELECT * FROM users WHERE username = '" + UserName + "'")
  
  # Fetch the first row of the result set
  row = cursor.fetchone()
  
  # Close the connection
  cnx.close()
  
  # Print the result
  print(row)
  
  # Print the result of the query
  print(cursor.rowcount)
  
  # Close the cursor
  cursor.close()
  
  # Close the connection
  cnx.close()
  
  # Exit the program
  exit()