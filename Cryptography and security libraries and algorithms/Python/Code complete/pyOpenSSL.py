import OpenSSL
from cryptography import x509
from cryptography.hazmat.backends import default_backend
#Load the certificate
cert = OpenSSL.crypto.load_certificate(OpenSSL.crypto.FILETYPE_PEM, open('/home/pi/Desktop/Certificates/server-certificate.pem').read())
#Get the public key from the certificate
publicKey = cert.get_pubkey()
#Convert it to a string in PEM format and print it out
print(OpenSSL.crypto.dump_publickey(OpenSSL.crypto.FILETYPE_PEM, publicKey))
