const WebSocket = require('ws');
//create a socket and bind it
const wss = new WebSocket.Server({ port: 8080 });
//when a client connects
wss.on('connection', function connection(ws) {
    //when a client sends a message
    ws.on('message', function incoming(message) {
        //send it back to the client
        ws.send(message);
    });
});