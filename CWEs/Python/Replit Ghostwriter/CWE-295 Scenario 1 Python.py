import paramiko
#define a function to open an SSH connection to example.com
def open_ssh_connection(hostname,username,password):
  # Create an SSH client object
  client = paramiko.SSHClient()
  # Set the SSH client's known hosts file
  client.load_system_host_keys()
  # Set the SSH client's host key to the one for example.com
  client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
  # Connect to the SSH server
  client.connect(hostname, username=username, password=password)
  # Return the SSH client object
  return client