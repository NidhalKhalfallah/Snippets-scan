import paramiko
#define a function to open an SSH connection to example.com
def ssh_command(ip, user, passwd, command):
    client = paramiko.SSHClient() #create an SSH Client object
    #client.load_host_keys('/home/justin/.ssh/known_hosts') #load host keys from file (optional)
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())#add missing host key to known hosts if not there already

    try: 
        client.connect(ip, username=user, password=passwd)#attempt connection to the server using supplied credentials and IP address of server

        stdin , stdout , stderr = client.exec_command(command)#execute command on remote machine

        print stdout.read() #print output of executed commands in a readable format

        for line in stdout: 
            print '... ' + line.strip('
