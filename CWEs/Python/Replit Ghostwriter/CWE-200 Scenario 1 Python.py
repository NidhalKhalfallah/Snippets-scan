import socket
#create a socket and bind it
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('', 9999))