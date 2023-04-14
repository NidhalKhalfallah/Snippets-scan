import bcrypt
import configparser
def verify_password(password):
        #verify if the password is correct
        #returns true if the password is correct, false otherwise
        #get the hashed password from the config file
        config = configparser.ConfigParser()
        config.read('config.ini')
        hashed_password = config['DEFAULT']['password']
        #compare the password with the hashed password
        if bcrypt.checkpw(password.encode('utf-8'), hashed password.encode('utf-8')):
            return True
            else:
            return False