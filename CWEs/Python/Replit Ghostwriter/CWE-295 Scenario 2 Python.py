import ssl
import socket
def get_ssl_certificate(ssl_sock):
    cert = ssl_sock.getpeercert()
    return cert
#Establish an SSL connection with the server
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 8443))
# Create a SSLContext object
ssl_context = ssl.SSLContext(ssl.PROTOCOL_SSLv23)
# Set the SSL version to TLSv1.2
ssl_context.set_ciphers('ECDHE+AESGCM:ECDHE+CHACHA20:ECDHE+AES256:ECDHE+AES128:ECDHE+AES:RSA+AESGCM:RSA+AES:!aNULL:!MD5:!DSS')
ssl_context.set_protocol_version(ssl.PROTOCOL_TLSv1_2)
ssl_context.verify_mode = ssl.CERT_REQUIRED
ssl_context.check_hostname = True
ssl_context.load_verify_locations('/Users/jason/Documents/certificates/server.crt')
# Create a connection with the server
ssl_sock = ssl_context.wrap_socket(sock, server_hostname='localhost')
# Get the certificate
cert = get_ssl_certificate(ssl_sock)
# Print the certificate
print(cert)
# Close the connection
ssl_sock.close()