import M2Crypto
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
cert_file = open("/etc/pki/tls/certs/server.crt", "r")
x509_obj = x509.load_pem_x509_certificate(cert_file.read(), default_backend())
#print the certificate information
print("Subject: ", x509_obj.subject)
print("Issuer: ", x509_obj.issuer)
