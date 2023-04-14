from cryptography.hazmat.primitives.asymmetric import dh

# Generate a DH key
dh_key = dh.generate_private_key(key_size=2048, backend=default_backend())
# Get the public key from the DH key
public_key = dh_key.public_key()
# Serialize to PEM format for exchange with server
serialized = public_key.public_bytes(encoding=serialization.Encoding.PEM, format=serialization.PublicFormat.SubjectPublicKeyInfo)


def getDHKey(): return serialized
