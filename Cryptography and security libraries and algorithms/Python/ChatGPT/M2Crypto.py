import M2Crypto
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
with open('path/to/cert.pem', 'rb') as f:
    cert_bytes = f.read()

cert = x509.load_pem_x509_certificate(cert_bytes, default_backend())