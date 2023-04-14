import mysql.connector
with open('Mydocs/config.txt') as fp:
    config = fp.read()
    #Get the user credentials then create the MySQL connection
config_dict = {}
for line in config.splitlines():
    key, value = line.split('=')
    config_dict[key.strip()] = value.strip()

# create MySQL connection using the config dictionary
try:
    cnx = mysql.connector.connect(**config_dict)
    print("Connection established")
    # do something with the connection here
except mysql.connector.Error as err:
    print(f"Something went wrong: {err}")
finally:
    cnx.close()
    print("Connection closed")
#Note that config.txt should have the following format:
#user=your_username
#password=your_password
#host=your_host
#database=your_database