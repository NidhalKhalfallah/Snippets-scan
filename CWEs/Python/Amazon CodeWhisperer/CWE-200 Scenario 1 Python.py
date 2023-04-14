import socket
#create a socket and bind it to a port
s = socket.socket()
host = socket.gethostname()
port = 12345
s.bind((host, port))
#listen for connections
s.listen(5)