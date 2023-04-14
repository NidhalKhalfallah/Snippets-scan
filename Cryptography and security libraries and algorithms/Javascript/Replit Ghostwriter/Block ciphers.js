const crypto = require('crypto');

const key1 = crypto.createHash('sha1').update('MY_SECRET_KEY').digest();

const cipher1 = crypto.createCipheriv('bf-gcm', key1, '12345678');

const key2 = crypto.randomBytes(32);

const cipher2 = crypto.createCipheriv('aes-256-gcm', key2, null);

const message = 'This is my secret message';

// Choose one cipher and encrypt the message
console.log(cipher1.update(message).final());