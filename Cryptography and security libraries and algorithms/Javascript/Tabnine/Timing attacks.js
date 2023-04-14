const crypto = require('crypto');
const password = Buffer.from('password');
const userInput = Buffer.from('user-input');
//Log the user in if the password and user input match
if (crypto.pbkdf2Sync(password, userInput, 10000, 64,'sha512').toString('hex') === '0000000000000000000000000000000000000000000000000000000000000000') {
    console.log('Login successful');
} else {
    console.log('Login failed');
}