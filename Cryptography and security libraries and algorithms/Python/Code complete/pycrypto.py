from cryptography.fernet import Fernet
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from Crypto.Cipher import AES
import os
key1 = Fernet.generate_key()
key2 = os.urandom(32)
#create a cipher object using the random key
cipher_encrypt = AES.new(key1,AES.MODE_EAX)
#encrypt the plaintext
ciphertext, tag = cipher_encrypt.encrypt_and_digest('Hello World!')
print (ciphertext)
print (tag)

