import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it
cipher_suite = Fernet(key_string)

def encrypt_password(password):
    """
    Encrypts the given password using Fernet encryption and returns the encrypted string.
    """
    encrypted_password = cipher_suite.encrypt(password.encode())
    return encrypted_password

def store_encrypted_password(username, encrypted_password):
    """
    Stores the encrypted password for the given username in a file.
    """
    with open(f"{username}.txt", "wb") as f:
        f.write(encrypted_password)