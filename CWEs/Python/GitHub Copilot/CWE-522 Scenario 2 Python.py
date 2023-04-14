import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    user, password = config.split()
    cnx = mysql.connector.connect(user=user, password=password, host='
localhost', database='test')
    cursor = cnx.cursor()
    #Create the table
    cursor.execute('CREATE TABLE IF NOT EXISTS test (id INT, name VARCHAR(20))')
    #Insert a row
    cursor.execute('INSERT INTO test VALUES (1, "Test")')
    #Commit the changes
    cnx.commit()
    #Close the connection
    cnx.close()