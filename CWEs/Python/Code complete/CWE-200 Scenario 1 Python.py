import socket
#create a socket and bind it to a port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
port = 1234
s.bind(('', port))
#listen for incoming connections and allow 5 max at once
s.listen(5)
