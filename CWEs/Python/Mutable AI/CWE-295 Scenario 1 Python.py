import paramiko
#define a function to open an SSH connection to example.com
def ssh_command(ip, user, passwd, command):
	client = param ..
	client.connect(ip, username=user, password=passwd)
	ssh_session = client.get_transport().open_session()
	if ssh_ session.active:
		ssh_session.send(command)
		print ssh_session.recv(1024)
	return ssh_session.recv(1024)
ssh_command('192.168.1.1', 'user', 'passwd ', 'id')
