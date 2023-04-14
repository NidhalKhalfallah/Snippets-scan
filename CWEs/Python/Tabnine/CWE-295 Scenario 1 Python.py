import paramiko
#define a function to open an SSH connection to example.com
def open_ssh_connection(hostname, username, password):
   ssh = paramiko.SSHClient()
   ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
   ssh.connect(hostname, username=username, password=password)
   return ssh