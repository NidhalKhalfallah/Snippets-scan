const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
const google = tls.connect(443,'www.google.com',()=>{console.log('connected to google')});
//establish a connection to https://www.facebook.com/
const facebook = net.createConnection(443,'www.facebook.com');
//event handler for the connection event, when we connect successfully, console log 'connected' and close the socket connection 
/*google.on('connect',()=>{console.log('connected to google');google=null;})*/
facebook .on('connect',()=>{console.log('connected to facebook');facebook=null;})

