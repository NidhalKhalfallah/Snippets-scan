import os
from cryptography.fernet import Fernet
key_string = b'my_key'
#write a function to encrypt a password entered by a user and store it

def encrypt(password):
  f = Fernet(key_string)
  return f.encrypt(password)