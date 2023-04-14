from cryptography.fernet import Fernet
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from Crypto.Cipher import AES
import os
key1 = Fernet.generate_key()
key2 = os.urandom(32)
#create a cipher
cipher = Cipher(algorithms.AES(key1), modes.ECB(), backend=Fernet(key2))