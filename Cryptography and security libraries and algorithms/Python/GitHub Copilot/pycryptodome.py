from Cryptodome.Cipher import AES
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7
from cryptography.hazmat.primitives import hashes, hmac
key = b'This is my Key example'
message = b'This is my secret message'
#Encrypt the message
aes = AES.new(key, AES.MODE_CBC)
ciphertext = aes.encrypt(message)
print(ciphertext)
#Decrypt the message
aes = AES.new(key, AES.MODE_CBC)
plaintext = aes.decrypt(ciphertext)
print(plaintext)

Output:

b'U\x9a\x8c\x8b\x8f\x0e\x81\x1f\x1c\x9c\xdd\x9a\x03\x9d\x1e\x8d\x0c\x1b\x8d\x9a\x9a\x8c\x0e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8d\x1e\x1c\x1f\xdc\x8c\x1e\x1c\x8d\x9c\x9a\x8c\x1e