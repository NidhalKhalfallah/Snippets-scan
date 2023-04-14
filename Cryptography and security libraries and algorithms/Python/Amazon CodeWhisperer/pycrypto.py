from cryptography.fernet import Fernet
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from Crypto.Cipher import AES
import os
key1 = Fernet.generate_key()
key2 = os.urandom(32)
#create a cipher object
cipher1 = Fernet(key1)
cipher2 = AES.new(key2, AES.MODE_CFB)