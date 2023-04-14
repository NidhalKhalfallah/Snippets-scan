from Cryptodome.Cipher import AES
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7
from cryptography.hazmat.primitives import hashes, hmac
key = b'This is my Key example'
message = b'This is my secret message'
#Encrypt the message
# Set up the cipher object
cipher = Cipher(algorithms.AES(key), modes.CBC(), backend=default_backend())

# Generate an initialization vector
iv = os.urandom(16)

# Encrypt the message
padder = PKCS7(128).padder()
padded_data = padder.update(message) + padder.finalize()

encryptor = cipher.encryptor()
ciphertext = encryptor.update(padded_data) + encryptor.finalize()

# Concatenate the IV and ciphertext for transmission
encrypted_message = iv + ciphertext