import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    config = config.split('\n')
    user = config[0].split('=')[1]
    password = config[1].split('=')[1]
    host = config[2].split('=')[1]
    database = config[3].split('=')[1]
    cnx = mysql.connector.connect(user=user , password=password , host=host , database=database)
    cursor = cnx .cursor()
    #Create the table if it doesn't exist already
    cursor.execute("CREATE TABLE IF NOT EXISTS mytable (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT )")
    #Insert some data into the table           
    cursor.execute("INSERT INTO mytable (name, age) VALUES (' ' , ' ')")
    #Commit the changes to the database           
    cnx.commit()
    #Close the connection to the database           
    cnx.close()           
    #Print the data to the screen           
    print("Data inserted successfully") 