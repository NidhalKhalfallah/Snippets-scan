const WebSocket = require('ws');
//create a socket and bind it
var ws = new WebSocket('ws://localhost:8080/');
ws.on('open', function () {
  console.log('connected');
  ws.send('hello');
});
ws.on('message', function (data) {
  console.log(data);
});
ws.on('close', function () {
  console.log('disconnected');
});
ws.on('error', function (err) {
  console.log('error:'+ err);
});