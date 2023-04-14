from Cryptodome.Cipher import AES
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7
from cryptography.hazmat.primitives import hashes, hmac
key = b'This is my Key example'
message = b'This is my secret message'
#Encrypt the message
cipher = Cipher(algorithms.AES(key), modes.ECB(),
                backend=hashes.SHA256(),
                padding=PKCS7(),
                )