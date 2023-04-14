import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection
ssl_sock = ssl.wrap_socket(socket.socket())
ssl_sock.connect(('www.google.com', 443))
#Get the certificate
cert = get_ssl_certificate(ssl_sock)
print cert
#Close the connection
ssl_sock.close()