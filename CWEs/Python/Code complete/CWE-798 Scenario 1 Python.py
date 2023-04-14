import bcrypt
import configparser
def verify_password(password):
        #verify if the password is correct
        config = configparser.ConfigParser()
        config.read('config/config.ini')
        salt = bcrypt.gensalt()
        hashed_password = bcrypt.hashpw(password, salt)

        if bcrypt.checkpw(password, hashed_password):
            return True
        else: 
            return False
