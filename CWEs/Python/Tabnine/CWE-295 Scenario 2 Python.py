import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection
context = ssl.create_default_context()
context.check_hostname = False
context.verify_mode = ssl.CERT_NONE
context.load_verify_locations(cafile=certifi.where())
context.load_cert_chain(certfile=certifi.where(), keyfile=certifi.where())