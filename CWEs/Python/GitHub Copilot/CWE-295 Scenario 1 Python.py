import paramiko
#define a function to open an SSH connection to example.com
def ssh_connect():
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect('example.com', username='user', password='password')
    return ssh