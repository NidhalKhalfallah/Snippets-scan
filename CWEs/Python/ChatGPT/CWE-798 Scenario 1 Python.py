import bcrypt
import configparser
def verify_password(password):
        #verify if the password is correct
 	config = configparser.ConfigParser()
    	config.read('config.ini')
    	stored_password = config.get('user', 'password')
    	return bcrypt.checkpw(password.encode('utf-8'), stored_password.encode('utf-8'))