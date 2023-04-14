import OpenSSL
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
with open("certificate.pem", "rb") as f:
    cert_data = f.read()

cert = x509.load_pem_x509_certificate(cert_data, default_backend())
#This assumes that the certificate is stored in a file named "certificate.pem" in the same directory as the script.