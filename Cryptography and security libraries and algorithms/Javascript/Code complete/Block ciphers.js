const crypto = require('crypto');

const key1 = crypto.createHash('sha1').update('MY_SECRET_KEY').digest();

const cipher1 = crypto.createCipheriv('bf-gcm', key1, '12345678');

const key2 = crypto.randomBytes(32);

const cipher2 = crypto.createCipheriv('aes-256-gcm', key2, null);

const message = 'This is my secret message';

// Choose one cipher and encrypt the message
const encrypted = cipher1.update(message, 'utf8', 'base64');
console.log('Encrypted message: ', encrypted);
// Decrypt the message using the other cipher
const decrypted = cipher2.update(encrypted, 'base64', 'utf8');
console.log('Decrypted message: ', decrypted);
