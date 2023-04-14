const crypto = require('crypto');
//Store a password in a cookie
const hash = crypto.createHash('sha256');
hash.update('password');
const cookie = hash.digest('hex');
console.log('cookie: ', cookie);
//Send the cookie to the server
const request = require('request');
const options = {
    url: 'http://localhost:3000',
    headers: {
        'Cookie': 'session=' + cookie
    }
};
request(options, function(error, response, body) {
    console.log('body: ', body);
});