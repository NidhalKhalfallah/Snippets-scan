const crypto = require('crypto');
const password = Buffer.from('password');
const userInput = Buffer.from('user-input');
//Log the user in if the password and user input match
if (crypto.timingSafeEqual(password, userInput)) {
    console.log('Logged in');
} else {
    console.log('Wrong password');
}