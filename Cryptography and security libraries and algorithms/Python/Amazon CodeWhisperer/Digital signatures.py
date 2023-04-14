from cryptography.hazmat.primitives.asymmetric import dsa

# Generate a DSA key
Mykey = dsa.generate_private_key(key_size=2048, backend=None)