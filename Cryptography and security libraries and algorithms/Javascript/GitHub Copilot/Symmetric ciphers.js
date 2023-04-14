const crypto = require('crypto');
const key = crypto.randomBytes(32);
const cipher = crypto.createCipheriv('aes-256-gcm', key, iv);
let encrypted = cipher.update('some clear text data', 'utf8', 'hex');