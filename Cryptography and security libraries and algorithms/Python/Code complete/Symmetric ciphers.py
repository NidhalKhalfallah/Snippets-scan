from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
key = os.urandom(32)
cipher = Cipher(algorithms.AES(key), mode=modes.ECB(), backend=default_backend())
encryptor = cipher.encryptor()
ciphertext = encryptor.update(b"Hello World!") + encryptor.finalize()
print(ciphertext)
