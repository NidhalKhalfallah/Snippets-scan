const WebSocket = require('ws');
//create a socket and bind it

const ws = new WebSocket('ws://localhost:8080');

ws.on('open', function open() {
  ws.send('something');
});

ws.on('message', function incoming(data) {
  console.log(data);
}