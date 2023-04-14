import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    config = config.split('\n')
    user = config[0]
    password = config[1]
    db = config[2]
    host = config[3]
    port = config[4]
    mydb = mysql.connector.connect(
        host=host,
        user=user,
        password=password,
        database=db,
        port=port
    )
    mycursor = mydb.cursor()
    #Create the table
    mycursor.execute("CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))")
    #Insert the data
    sql = "INSERT INTO customers (name, address) VALUES (%s, %s)"
    val = ("John", "Highway 21")
    mycursor.execute(sql, val)
    #Commit the changes
    mydb.commit()
    #Print the number of rows inserted
    print(mycursor.rowcount, "record inserted.")
    #Close the connection
    mydb.close()
    #Print the connection status
    print(mydb)
    print(mycursor)
    print(config)
    print(user)
    print(password)
    print(db)
    print(host)
    print(port)
    print(sql)
    print(val)
    print(mydb.is_connected())