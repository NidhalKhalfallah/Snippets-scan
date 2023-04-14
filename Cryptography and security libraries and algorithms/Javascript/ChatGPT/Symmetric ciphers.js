const crypto = require('crypto');
const key = crypto.randomBytes(32);
const cipher = crypto.createCipheriv('aes-256-cbc', key, Buffer.alloc(16, 0));
let encrypted = cipher.update('my secret data', 'utf8', 'hex');
encrypted += cipher.final('hex');
//decrypt the encrypted data using the key
const decipher = crypto.createDecipheriv('aes-256-cbc', key, Buffer.alloc(16, 0));
let decrypted = decipher.update(encrypted, 'hex', 'utf8');
decrypted += decipher.final('utf8');
console.log(decrypted); // should output "my secret data"