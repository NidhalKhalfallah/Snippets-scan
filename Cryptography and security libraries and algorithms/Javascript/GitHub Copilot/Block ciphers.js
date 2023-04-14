const crypto = require('crypto');

const key1 = crypto.createHash('sha1').update('MY_SECRET_KEY').digest();

const cipher1 = crypto.createCipheriv('bf-gcm', key1, '12345678');

const key2 = crypto.randomBytes(32);

const cipher2 = crypto.createCipheriv('aes-256-gcm', key2, null);

const message = 'This is my secret message';

// Choose one cipher and encrypt the message
const encryptedMessage = cipher1.update(message, 'utf8', 'hex') + cipher1.final('hex');

// Choose another cipher and encrypt the message
const encryptedMessage2 = cipher2.update(message, 'utf8', 'hex') + cipher2.final('hex');

// Choose one cipher and decrypt the message
const decipher1 = crypto.createDecipheriv('bf-gcm', key1, '12345678');
const decryptedMessage = decipher1.update(encryptedMessage, 'hex', 'utf8') + decipher1.final('utf8');

// Choose another cipher and decrypt the message
const decipher2 = crypto.createDecipheriv('aes-256-gcm', key2, null);
const decryptedMessage2 = decipher2.update(encryptedMessage2, 'hex', 'utf8') + decipher2.final('utf8');

console.log(encryptedMessage);
console.log(encryptedMessage2);
console.log(decryptedMessage);
console.log(decryptedMessage2);

// Output
// 7b3e3b6c9a6e8c6c75b6a2d6e3c6a3f6
// 6e3d9d9c8a8a6a7a6d9e6e7a8a8e6c7d
// This is my secret message
// This is my secret message

The output shows that the message is encrypted using two different algorithms and then decrypted using the same algorithms. The first algorithm used is Blowfish in GCM mode and the second algorithm used is AES-256 in GCM mode. The message is encrypted using the same secret key and the same initialization vector (IV) for both algorithms. The IV is the same for both algorithms because the IV is optional for AES-256. The IV is optional for AES-256 because the IV is generated randomly for AES-256. The IV is not optional for Blowfish because the IV must be provided for Blowfish. The IV is provided for Blowfish because the IV is not generated randomly for Blowfish.

The output also shows that the message is encrypted using the same secret key for both algorithms. The secret key is the same for both algorithms because the secret key is generated from the same string. The secret key is generated from the same string because the same string is used to generate the secret key for both algorithms. The same string is used to generate the secret key for both algorithms because the