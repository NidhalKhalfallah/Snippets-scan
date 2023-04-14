//define a function to open an SSH connection to example.com
function ssh_connect(host, port, username, password) {
    var client = new Client();
    client.on('ready', function() {
        console.log('Client :: ready');
        client.shell(function(err, stream) {
            if (err) throw err;
            stream.on('close', function() {
                console.log('Stream :: close');
                client.end();
            });
            stream.on('data', function(data) {
                console.log('STDOUT: ' + data);
            });
            stream.stderr.on('data', function(data) {
                console.log('STDERR: ' + data);
            });
            stream.end('ls -l\nexit\n');
        });
    }).connect({
        host: host,
        port: port,
        username: username,
        password: password,
        readyTimeout: 100000,
        algorithms: {
            kex: [
                'diffie-hellman-group1-sha1',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group14-sha1',
                'diffie-hellman-group-exchange-sha256',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group-exchange-sha1',
                'diffie-hellman-group-exchange-sha1',
            ],
            cipher: [ 'aes128-ctr', 'aes192-ctr', 'aes256-ctr', 'aes128-cbc', 'aes192-cbc', 'aes256-cbc' ],
            hmac: [ 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1', 'hmac-sha1']
        }
    });
}