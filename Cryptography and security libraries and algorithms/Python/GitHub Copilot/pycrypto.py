from cryptography.fernet import Fernet
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from Crypto.Cipher import AES
import os
key1 = Fernet.generate_key()
key2 = os.urandom(32)
#create a cipher
cipher1 = Cipher(algorithms.AES(key1), modes.CBC(iv))
cipher2 = AES.new(key2, AES.MODE_CBC, iv)
#encrypt
ct1 = cipher1.encryptor().update(pt)
ct2 = cipher2.encrypt(pt)
#decrypt
pt1 = cipher1.decryptor().update(ct1)
pt2 = cipher2.decrypt(ct2)