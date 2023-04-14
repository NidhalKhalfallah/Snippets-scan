import socket, ssl

#establish a connection to https://www.google.com/
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('www.google.com', 443))
s = ssl.wrap_socket(s)
s.connect(('www.google.com', 443))
