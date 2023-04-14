const crypto = require('crypto');
const key = crypto.randomBytes(32);
const cipher = crypto.createCipheriv('aes-256-cbc', key, 'a');
const decipher = crypto.createDecipheriv('aes-256-cbc', key, 'a');
let encrypted = cipher.update(JSON.stringify({ test: 1 }), 'utf8', 'hex');
encrypted += cipher.final('hex');
console.log(encrypted); // => f6e1b2f7d4b9f0bf5ef3ddfba34e05ec
