const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
const options = {
  host: 'www.google.com',
  port: 443
};

const socket = tls.connect(options, () => {
  console.log('connected');
  socket.write('GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n');
});

socket.on('data', (data) => {
  console.log(data.toString());
});

socket.on('error', (error) => {
  console.error(error);
});

socket.on('end', () => {
  console.log('disconnected');
});