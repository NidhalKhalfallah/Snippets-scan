from cryptography.hazmat.primitives.asymmetric import dh

# Generate a DH key
dh_key = dh.generate_private_key(key_size=1024)