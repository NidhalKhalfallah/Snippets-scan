import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssl_sock = ssl.wrap_socket(sock, ssl_version=ssl.PROTOCOL_SSLv23)
ssl_sock.connect(('www.google.com', 443))
#Get the certificate of the SSL connection
cert = get_ssl_certificate(ssl_sock)
print(cert)