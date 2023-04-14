import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it in a file
#write a function to decrypt the password and print it out to the user
def encrypt(key, string):
    f = Fernet(key)
    encrypted_password = f.encrypt(string)
    return encrypted_password

    
def decrypt(key, string):
    f = Fernet(key)  # create a cipher object using the key 

    decrypted_password = f.decrypt(string)  # decrypt with that key 

    return decrypted_password
