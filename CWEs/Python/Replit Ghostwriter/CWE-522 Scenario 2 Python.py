import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    user = config.split(':')[0]
  
    password = config.split(':')[1]
  
    host = config.split(':')[2]
  
    database = config.split(':')[3]
  
    #Connect to the database
    try:
        cnx = mysql.connector.connect(user=user, password=password, host=host, database=database)
      
        #Create a cursor object using cursor() method
        cursor = cnx.cursor()
      
        #Execute a query
        cursor.execute("SELECT * FROM users")
      
        #Fetch all the rows in a list of lists.
        #The result is a list of lists.
        #Each row is a list.
        #Each column is a string.
        #The first list is the column headers.
        #The second list is the values for each row.
        #print(cursor.fetchall())

        #Close the connection
        cnx.close()
      
    except mysql.connector.Error as err:
        if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
            print("Something is wrong with your user name or password")
          
        elif err.errno == errorcode.ER_BAD_DB_ERROR:
            print("Database does not exists")
          
        else:
            print(err)
          
    except mysql.connector.Error as err:
        print(err)