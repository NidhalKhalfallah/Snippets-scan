const crypto = require('crypto');
const key = crypto.randomBytes(32);
const cipher = crypto.createCipheriv('aes-256-CBC', key, iv);
const encrypted = Buffer.concat([cipher.update( 'some clear text data' ), cipher.final()])