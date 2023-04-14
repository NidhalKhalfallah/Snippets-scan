const nets = require('nets');
//connect to a network that has a name and a password
const net = new nets.Net();
net.on('connect', () => {
    console.log('connected');
    net.on('data', (data) => {
        console.log(data);