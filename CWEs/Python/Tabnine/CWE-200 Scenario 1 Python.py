import socket
#create a socket and bind it
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 9999))
s.listen(5)
print('waiting for connection...')
conn, addr = s.accept()
print('connection from', addr)