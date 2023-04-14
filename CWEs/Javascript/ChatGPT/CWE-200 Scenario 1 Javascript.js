const WebSocket = require('ws');
//create a socket and bind it
const wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', (ws) => {
  console.log('Client connected');

  ws.on('message', (message) => {
    console.log(`Received message: ${message}`);

    // Echo the message back to the client
    ws.send(`You sent: ${message}`);
  });

  ws.on('close', () => {
    console.log('Client disconnected');
  });
});