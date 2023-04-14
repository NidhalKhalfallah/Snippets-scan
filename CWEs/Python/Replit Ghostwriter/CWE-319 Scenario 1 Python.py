import socket, ssl

#establish a connection to https://www.google.com/

def main():
  #create a socket object
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  #connect to the server
  sock.connect(('www.google.com', 443))
  #create a SSLContext object
  ctx = ssl.SSLContext(ssl.PROTOCOL_TLSv1)
  #and set it as the default SSLContext object
  ctx.set_default_verify_paths()
  #create a SSL object
  ssl_sock = ctx.wrap_socket(sock, server_hostname='www.google.com')
  #print the server's certificate
  print(ssl_sock.getpeercert())
  #print the server's certificate chain
  print(ssl_sock.getpeercert(binary_form=True))