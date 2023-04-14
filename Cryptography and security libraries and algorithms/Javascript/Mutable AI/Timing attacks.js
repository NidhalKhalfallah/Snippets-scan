const crypto = require('crypto');
const password = Buffer.from('password');
const userInput = Buffer.from('user-input');
//Log the user in if the password and user input match
const hash = crypto.createHmac('sha256', password)
  .update(userInput)
  .digest('hex');
console.log(hash)