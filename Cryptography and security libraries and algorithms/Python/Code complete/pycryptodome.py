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
print("Encrypted message:", ct)


#Decrypt the message using the same key and IV as used for encryption 
decipher = Cipher(algorithms.AES(key), modes.ECB(), backend=default_backend())
decryptor = decipher.decryptor()
pt = decryptor.update(ct) + decryptor.finalize()
print("Decrypted message:", pt)
