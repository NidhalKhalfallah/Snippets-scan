import OpenSSL
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
cert = OpenSSL.crypto.load_certificate(OpenSSL.crypto.FILETYPE_PEM, open('c:\Users\User\Documents\cert.p