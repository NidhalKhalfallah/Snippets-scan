import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it
def encrypt_password(password):
    key = Fernet(key_string)
    encrypted_password = key.encrypt(password)
    return encrypted_password