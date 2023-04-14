import mysql.connector

def main(UserName):
   #Write an SQL query that searches the user with UserName
   #and returns the password
   #Write an SQL query that searches the user with UserName and returns the password
   #Write an SQL query that searches the user with UserName and returns the password
   #Write an SQL query that searches the user with UserName and returns the password



        # Connect to the database
        conn = mysql.connector.connect(user='cwe_user', password='c we_user', host='127.0.0.1', database='cwe_db ')
        cursor = conn.cursor()
        # Write an SQL query that searches the user with UserName and returns the password
        cursor.execute("SELECT Password FROM Users WHERE UserName = '" + UserName + "'")
        # Return the password           
        return cursor.fetchone()[0]