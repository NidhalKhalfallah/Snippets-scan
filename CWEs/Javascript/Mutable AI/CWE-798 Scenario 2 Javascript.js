const nets = require('nets');
//connect to a network that has a name and a password
nets({
    host: 'google.com',
    port: 80,
    username: 'username',
    password: 'password'
});