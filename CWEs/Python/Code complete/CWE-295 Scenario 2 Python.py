import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection to the server
def get_ssl_connection(hostname, port):
    context = ssl.create_default_context()
    sslsock = context.wrap_socket(socket.socket(), server_hostname=hostname)
    sslsock.connect((hostname, port))

    return sslsock
