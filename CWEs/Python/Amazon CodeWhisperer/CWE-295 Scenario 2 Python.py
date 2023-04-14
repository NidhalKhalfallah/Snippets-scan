import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection to a server
ssl_sock = ssl.wrap_socket(socket.socket(socket.AF_INET, socket.SOCK_STREAM))
ssl_sock.connect(('www.python.org', 443))
#Get the certificate
cert = get_ssl_certificate(ssl_sock)
#Print the certificate
print(cert)
#Close the connection
ssl_sock.close()