import socket, ssl

#establish a connection to https://www.google.com/
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ssl_sock = ssl.wrap_socket(s)
ssl_sock.connect(('www.google.com', 443))