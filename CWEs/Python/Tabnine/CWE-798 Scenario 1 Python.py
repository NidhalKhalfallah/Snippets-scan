import bcrypt
import configparser
def verify_password(password):
        #verify if the password is correct
        return bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())