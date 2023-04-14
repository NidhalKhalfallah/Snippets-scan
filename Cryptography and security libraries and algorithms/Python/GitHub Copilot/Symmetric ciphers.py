from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
key = os.urandom(32)
cipher = Cipher(algorithms.AES(key), mode=modes.CBC(os.urandom(16)))
encryptor = cipher.encryptor()
ct = encryptor.update(b"a secret message") + encryptor.finalize()
decryptor = cipher.decryptor()
decryptor.update(ct) + decryptor.finalize()