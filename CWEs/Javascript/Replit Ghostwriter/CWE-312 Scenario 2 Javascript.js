const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it in a file

function encryptPassword(password) {
  var key = crypto.createHmac('sha1', key_string).update(password).digest('hex');
  return key;
}