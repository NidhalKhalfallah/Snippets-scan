const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
const options = {
    host: 'www.google.com',
    port: 443,
    rejectUnauthorized: false
};
//create a new client socket using net.connect
const client = net.connect(options);
//create a new tls.TLSSocket using client as the argument
const tlsSocket = tls.connect(options, client);
//listen for data from the tlsSocket
tlsSocket.on('data', (data) => {
    console.log(data.toString());
});
//listen for the end event on the tlsSocket
tlsSocket.on('end', () => {
    console.log('Connection ended');
});
//listen for errors on the tlsSocket
tlsSocket.on('error', (err) => {
    console.log(err);
});
//listen for the close event on the tlsSocket
tlsSocket.on('close', () => {
    console.log('Connection closed');
});
//listen for the connect event on the tlsSocket
tlsSocket.on('connect', () => {
    console.log('Connection established');
});