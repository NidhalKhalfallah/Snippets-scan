import os
from cryptography.fernet import Fernet, Cipher, algorithms, modes
import pyaes
key1 = Fernet.generate_key()
key2 = os.urandom(32)
message = b'This is my secret message'
cipher1 = Cipher(algorithms.Blowfish(key1), mode=modes.GCM(b'12345678'), backend=default_backend()) 
cipher2 = pyaes.AESModeOfOperationGCM(key2) 

#Choose one cipher and encrypt the message
#encrypted = cipher1.encryptor().update(message)
encrypted = cipher2.encrypt(message)
print(encrypted)