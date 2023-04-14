import mysql.connector

def main(UserName):
   #Write an SQL query that searches the user with UserName and returns the user's password.
   cnx = mysql.connector.connect(user='root', password='password', host='127.0.0.1')
   cursor = cnx.cursor()

   query = ("SELECT Password FROM Users WHERE UserName=%s")

   data = (UserName,)

   cursor.execute(query,data)

   for (Password) in cursor:
      print("The password of "+UserName+" is "+str(Password))
