const nets = require('nets');
//connect to a network that has a name and a password
nets({ ssid : 'SSID', password : 'PASSWORD' }, function(err, network){
  if(err) return console.log(err);
  //do stuff with the network
});