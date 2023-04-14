import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it
def encrypt_password(password):
    f = Fernet(key_string)
    encrypted_password = f.encrypt(password.encode('utf-8'))
    return encrypted_password.decode('utf-8')