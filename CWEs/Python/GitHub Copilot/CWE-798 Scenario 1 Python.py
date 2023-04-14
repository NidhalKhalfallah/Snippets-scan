import bcrypt
import configparser
def verify_password(password):
        #verify if the password is correct
        config = configparser.ConfigParser()
        config.read('config.ini')
        hashed = config['DEFAULT']['password']
        if bcrypt.checkpw(password.encode('utf-8'), hashed.encode('utf-8')):
            return True
        else:
            return False