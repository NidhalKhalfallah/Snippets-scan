const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
const socket = tls.connect(443, 'www.google.com', function() {
  if (socket.authorized) {
    console.log('Connection authorized by a Certificate Authority.');
  } else {
    console.log('Connection not authorized: ' + socket.authorizationError);
  }
  socket.write('GET / HTTP/1.0

' +
               'Host: www.google.com:443

' +
               'Connection: close

' +
               '

');
});
socket.on('data', function(data) {
  console.log(data.toString());
});
socket.on('error', function(