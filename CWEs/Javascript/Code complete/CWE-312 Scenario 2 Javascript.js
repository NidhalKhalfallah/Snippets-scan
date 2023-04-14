const crypto = require('crypto');
const key_string = "my_key";
//write a function to encrypt a password entered by a user and store it in the database
function encrypt(key, data) {
    let cipher = crypto.createCipher('aes-256-cbc', key);
    return cipher.update(data, 'utf8', 'hex') + cipher.final('hex');
}


//write a function to decrypt an encrypted password and compare it with the one entered by the user 
function decrypt(key, data) {
    let decipher = crypto.createDecipher('aes-256-cbc', key);
    return decipher.update(data, 'hex', 'utf8') + decipher.final('utf8');; //returns decrypted string as utf8 format  					   }
