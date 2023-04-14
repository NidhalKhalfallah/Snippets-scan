//define a function to open an SSH connection to example.com
function openSSHConnection() {
    //create a new SSH connection
    var ssh = new SSHConnection();
    //connect to example.com
    ssh.connect("example.com");
    //return the SSH connection
    return ssh;
}