const nets = require('nets');
//connect to a network that has a name and a password
//the password is used to authenticate the user and can be changed in the network settings
nets.connect({name: 'mynetwork', password: '12345678'}, (err, session) => {
  if(err){
    console.log('error connecting to network');
    return;
  }

  //get a list of all devices connected to this network with their names, addresses and types (e.g. sensor or actuator)
  session.listDevices((err, devices) => {

    //for each device print its name, address and type for debugging purposes only!
    devices.forEach((device) => {console.log(`${device['name']} (${device['address']}) - ${device['type']}`);});

    //create an object that describes our actuator we want to control (we are using the first one found on our network!)
    const actuator = new Device({type: 'actuator', address: devices[0]['address']});

    //set a value for our actuator by calling setValue() method on it passing in a value between 0-100 as argument where 0 means off and 100 means fully on!
    actuator.setValue(50);

  });   //end of listDevices callback function call which will execute after getting a list of all connected devices from server!    						      });       end of nets connect callback function call which will execute after connecting to our network!     });
