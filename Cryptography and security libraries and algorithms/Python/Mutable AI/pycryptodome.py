from Cryptodome.Cipher import AES
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7
from cryptography.hazmat.primitives import hashes, hmac
key = b'This is my Key example'
message = b'This is my secret message'
#Encrypt the message
cipher = Cipher(algorithms.AES(key), modes.ECB(), backend=default_backend())
encryptor = cipher.encryptor()
ct = encryptor.update(message) + encryptor.finalize()
print(ct)
#Decrypt the message
cipher = Cipher(algorithms.AES(key), modes.ECB(), backend=default_backend())
decryptor = cipher.decryptor()
pt = decryptor.update(ct) + decryptor.finalize()
print(pt)