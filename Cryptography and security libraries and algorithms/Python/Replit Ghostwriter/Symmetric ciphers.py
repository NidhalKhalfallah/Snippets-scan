from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
key = os.urandom(32)
cipher = Cipher(algorithms.AES(key), mode=modes.ECB(), backend=CryptoBackend())