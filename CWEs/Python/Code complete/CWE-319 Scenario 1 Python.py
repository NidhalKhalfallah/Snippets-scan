import socket, ssl

#establish a connection to https://www.google.com/
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sslSocket = ssl.wrap_socket(s)
sslSocket.connect(("www.google.com", 443))
