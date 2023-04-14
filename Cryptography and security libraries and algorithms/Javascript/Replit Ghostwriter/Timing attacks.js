const crypto = require('crypto');
const password = Buffer.from('password');
const userInput = Buffer.from('user-input');
//Log the user in if the password and user input match
if (crypto.createHash('sha256').update(password).digest('hex') === crypto.createHash('sha256').update(userInput).digest('hex')) {
  console.log('User is logged in');
} else {
  console.log('User is not logged in');
}