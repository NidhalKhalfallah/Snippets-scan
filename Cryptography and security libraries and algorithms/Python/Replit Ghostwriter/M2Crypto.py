import M2Crypto
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
cert = x509.load_certificate(open("cert.pem", "rb"))