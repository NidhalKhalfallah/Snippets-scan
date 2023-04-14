const WebSocket = require('ws');
//create a socket and bind it to the port
const wss = new WebSocket.Server({port: 8080});
//create a variable for the current number of connected clients
var numClients = 0;
//when a client connects, increase the number of connected clients by one and send an update to all other clients with the new number of connected clients 
wss.on('connection', function(ws) {
    ++numClients;

    ws.send(JSON.stringify({type:'numberOfConnectedClients', data: numClients}));

    //when a message is received from a client, broadcast it to all other clients except for itself (the sender) 
    ws.on('message', function(data) {

        var msgObj = JSON.parse(data);

        if (msgObj['type'] == 'chatMessage'){

            console.log("new chat message!");

            var msgData = msgObj['data'];

            //broadcast the message to all other sockets except for itself (the sender) 
            wss.clients.forEach((client, index) => {   //iterate through each socket in our array of sockets 
                if (client != this){                   //if that socket isn't us... 
                    client.send(JSON.stringify({type:'chatMessage', data:msgData}));   //send out that message! Yay! :)     }})});                                                               });      })};       });          });           });              }});
