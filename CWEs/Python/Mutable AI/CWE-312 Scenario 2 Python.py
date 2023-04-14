import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it
#in a file called password.txt
def encrypt_password(password):
    #create a key from the key_string
    key = Fernet.generate_key()
    #create a fernet object
    f = Fernet(key)
    #encrypt the password with the key and encode it with base64
    encrypted_password = f.encrypt(password.encode())
    #write the encrypted password to a file called password.txt
    with open('password.txt', 'wb') as f:
        f.write(encrypted_password)
#write a function to decrypt the password