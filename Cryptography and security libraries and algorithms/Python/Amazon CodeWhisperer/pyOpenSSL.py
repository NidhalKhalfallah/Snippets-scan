import OpenSSL
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
cert = x509.load_pem_x509_certificate(open('certificate.pem').read(), default_backend())