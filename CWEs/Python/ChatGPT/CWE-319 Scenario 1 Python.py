import socket, ssl

#establish a connection to https://www.google.com/
hostname = "www.google.com"
context = ssl.create_default_context()

# Establish a connection to the server
with socket.create_connection((hostname, 443)) as sock:
    with context.wrap_socket(sock, server_hostname=hostname) as ssock:
        # Send an HTTP GET request to the server
        ssock.sendall(b"GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n")
        # Receive the response from the server
        response = ssock.recv(4096)
        print(response.decode())