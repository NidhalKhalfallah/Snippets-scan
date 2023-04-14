import M2Crypto
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
with open('cert.pem', 'rb') as f:
    cert = x509.load_pem_x509_certificate(f.read(), default_backend())