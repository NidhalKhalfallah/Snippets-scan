import mysql.connector

def main(UserName):
   #Write an SQL query that searches the user with UserName
   sql = "SELECT * FROM users WHERE username = %s"
   try:
      conn = mysql.connector.connect(host="localhost", user="root", password="root", database="test")
      cursor = conn.cursor()
      cursor.execute(sql, (UserName,))
      results = cursor.fetchall()
      print(results)
      conn.close()
   except mysql.connector.Error as err:
      print(err)