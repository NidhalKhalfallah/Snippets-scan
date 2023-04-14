import socket, ssl

#establish a connection to https://www.google.com/
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM);
s.connect(('www.google.com', 443));
#create a secure connection using SSL.
ssl_sock = ssl.wrap_socket(s, ssl_version=ssl.PROTOCOL_TLSv1);