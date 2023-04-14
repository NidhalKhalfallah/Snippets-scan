const nets = require('nets');
//connect to a network that has a name and a password
nets.connect('name', 'password', function(err, net) {
  if (err) {
    console.log(err);
  } else {
    console.log('connected to network');
    // get the node
    var node = net.getNode('node');
    // get the node's address
  
    node.on('data', function(data) {
      console.log(data);
    });
  }
});