const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it
function encrypt_password(password) {
    return crypto.createHmac('sha256', key_string).update(password).digest('hex');