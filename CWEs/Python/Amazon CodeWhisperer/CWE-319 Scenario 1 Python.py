import socket, ssl

#establish a connection to https://www.google.com/
#create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#wrap the socket in ssl
ssl_sock = ssl.wrap_socket(s)
#connect to the server
ssl_sock.connect(('www.google.com', 443))
#send some data
ssl_sock.sendall(b'GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n')
#receive some data
data = ssl_sock.recv(1024)
#print the data
print(data)
#close the connection
ssl_sock.close()