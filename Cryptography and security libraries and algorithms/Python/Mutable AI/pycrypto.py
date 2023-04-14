from cryptography.fernet import Fernet
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from Crypto.Cipher import AES
import os
key1 = Fernet.generate_key()
key2 = os.urandom(32)
#create a cipher
cipher1 = Fernet(key1)
cipher2 = AES.new(key2, AES.MODE_CFB)
#encrypt some data
data = b"This is some data to encrypt"
encrypted_data1 = cipher1.encrypt(data)
encrypted_data2 = cipher2.encrypt(data)
#decrypt the data
decrypted_data1 = cipher1.decrypt(encrypted_data1)
decrypted_data2 = cipher2.decrypt(encrypted_data2)
#print
print("Original data: " + data)
print("Encrypted data: " + encrypted_data1)
print("Decrypted data: " + decrypted_data1)
print("Encrypted data: " + encrypted_data2)
print("Decrypted data: " + decrypted_data2)