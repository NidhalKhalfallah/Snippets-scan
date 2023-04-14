const nets = require('nets');
//connect to a network that has a name and a password
nets.post('http://00000000000/api/login', {
    username: 'XXXXX',
    password: 'XXXXX'
}, function (err, resp, body) {
    console.log(resp.statusCode);
    console.log(body);
});