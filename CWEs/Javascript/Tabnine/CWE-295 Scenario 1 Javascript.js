//define a function to open an SSH connection to example.com
function openSSHConnection() {
    var ssh = require('ssh2');
    var conn = new ssh();
    conn.on('ready', function() {
        console.log('SSH connection ready');
    });
    conn.on('error', function(err) {
        console.log('SSH connection error:'+ err);
    });
    conn.on('close', function() {
        console.log('SSH connection closed');
    });
    conn.connect({
        host: 'example.com',
        port: 22,
        username: 'root',
        password: 'password'
    });
    return conn;