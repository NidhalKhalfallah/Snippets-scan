const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
var client = tls.connect({
  port: 443,
  host: 'www.google.com',
  rejectUnauthorized: false
}, function() {
  console.log('connected');
  //send a request to https://www.google.com/
                         client.write('GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n');
  //read the response
  client.on('data', function(data) {
    console.log('received:'+ data.toString());
    //close the connection
    client.end();
  });
});