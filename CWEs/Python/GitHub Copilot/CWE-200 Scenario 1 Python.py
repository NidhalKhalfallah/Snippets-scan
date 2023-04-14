import socket
#create a socket and bind it
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 12345))