import socket
#create a socket and bind it
# create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# bind the socket to a specific port
server_address = ('localhost', 10000)
sock.bind(server_address)