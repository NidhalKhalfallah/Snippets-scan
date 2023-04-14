from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
import os
key = os.urandom(32)
cipher = Cipher(algorithms.AES(key), mode=modes.CBC())

# You can also set the IV explicitly:
iv = os.urandom(16)
cipher = Cipher(algorithms.AES(key), mode=modes.CBC(iv))

# Once you have a cipher object, you can use it to create an encryptor and decryptor:
encryptor = cipher.encryptor()
decryptor = cipher.decryptor()