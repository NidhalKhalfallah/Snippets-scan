import paramiko
#define a function to open an SSH connection to example.com
def ssh_connection(ip):
    #define the connection object
    ssh_client = paramiko.SSHClient()
    #set the policy to accept all host keys
    ssh_client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    #connect to the host
    ssh_client.connect(hostname=ip,username='XXXX',password='root')
    return ssh_client