import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    config = config.splitlines()
    user_name = config[0]
    password = config[1]
    host_name = config[2]
    database_name=config[3]

     #create the MySQL connection instance 
mydb = mysql.connector.connect(user=user_name,password=password,host=host_name,database=database_name)
