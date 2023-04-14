from cryptography.hazmat.primitives.asymmetric import dsa

# Generate a DSA key
Mykey = dsa.generate_private_key(key_size=1024, backend=default_backend())
Mykey = Mykey.private_bytes(encoding=Encoding.PEM,format=PrivateFormat.PKCS8,encryption_algorithm=NoEncryption())
print('