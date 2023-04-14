import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
    user, password, host, database = config.split(';')

# Connect to the database
cnx = mysql.connector.connect(user=user, password=password, host=host, database=database)
cursor = cnx.cursor()
cursor.execute("SELECT * FROM users")
rows = cursor.fetchall()
for row in rows:

    print(row)
cnx.close()
cursor.close()
cnx.close()
print("Done")